################ CONSTANT DEFINITIONS ################
ConstantC         = 0.5 # Velocity constant
WorldSize         = 10.0 # Size of the world, in meters
ArraySize         = 128 # Number of elements in array
delta_x           = WorldSize/ArraySize
delta_t           = 1.0/24.0
######################################################


######################################################
#### Question P1
## Define the states


StateI_J = [0.0,[0.0]*ArraySize]

StateI_J_previous = [0.0,[0.0]*ArraySize]

StateI_GS = [0.0,[0.0]*ArraySize]

StateI_GS_previous = [0.0,[0.0]*ArraySize]

StateCN_J = [0.0,[0.0]*ArraySize]

StateCN_J_previous = [0.0,[0.0]*ArraySize]

StateCN_GS = [0.0,[0.0]*ArraySize]

StateCN_GS_previous = [0.0,[0.0]*ArraySize]

StateTime = 0

StateTemperature = 1

## End of question P1
######################################################


######################################################
#### Question P2
def EnforceBoundaryConditions(array):
    # Apply Neumann boundary conditions
    array[0] = array[1]
    array[ArraySize-1] =  array[ArraySize-2]
    
#### End of question P2
######################################################


def setup():
    ##################################################
    #### Question P1
    ##
    # Initialize the states
    for i in range(0, ArraySize-1):
        random_var = random (0.25, 0.75)
        
        StateI_J[StateTemperature][i] = random_var

        StateI_J_previous[StateTemperature][i] = random_var

        StateI_GS[StateTemperature][i] = random_var

        StateI_GS_previous[StateTemperature][i] = random_var

        StateCN_J[StateTemperature][i] = random_var

        StateCN_J_previous[StateTemperature][i] = random_var

        StateCN_GS[StateTemperature][i] = random_var

        StateCN_GS_previous[StateTemperature][i] = random_var

    ## End of question P1
    ##################################################

    # Set window size and style for visualization
    size(800, 900)
    colorMode(RGB, 1.0)
    strokeWeight(0.5)
    textSize(24)


######################################################
#### Question P4
## Calculate the error using the L2 distance
def ComputeError(array_previous, array_next):
    up = 0
    down = 0
    for i in range (ArraySize):
        up +=  (array_next[i]-array_previous[i])**2
        down += array_next[i]**2
        
    return sqrt(up/down)

## End of question P4
######################################################


def TimeStep(array, array_previous, discretization, solver):
    # Maximum iterations and error threshold
    maxIterations = 20
    threshold = -1  #1e-10 # For Question P4
    
    ##################################################
    #### Question P3.1
    ## Define the constants to be used and assign their values.
    # 1. mu (amalgamation of constants)
    if discretization == 'Implicit':
    # mu (amalgamation of constants) for Implicit method
        mu = (ConstantC**2)*((delta_t**2)/(delta_x**2))
    if discretization == 'Crank-Nicolson':
    # mu (amalgamation of constants) for Crank-Nicolson method
        mu = (ConstantC**2)*((delta_t**2)/(2*(delta_x**2)))
    # 3. aii (diagonal)
    aii = 1+2*mu
    # 2. aij (upper and lower diagonal)
    aij = -mu
    
    #### End of question P3.1
    ##################################################
    
    ##################################################
    #### Question P3.2
    # 1. Initialize data structures for the matrix operation A*x=b
    # Create vector b of size ArraySize for computing the solver's formula
    b = [0.0]*ArraySize
    # 2. Create an auxiliary vector u^{(m+1),(n)} of ArraySize, and initialize 
    # it by copying the array's contents into it
    uCurrent = [0.0]*ArraySize
    for idx in range(ArraySize):
        uCurrent[idx] = array[StateTemperature][idx]
    
    # 3. Create an empty auxiliary vector u^{(m+1),(n+1)} of ArraySize, to store next iteration
    uNext = [0.0]*ArraySize
    #### End of question P3.2
    ##################################################
    
    
    # Iterative Solver implementation:
    for iteration in range(maxIterations):
        # Iterative loop: apply jacobi formula to calculate each cell of next x
        # Exclude the boundaries in the loop! They will be updated using boundary 
        # conditions
        for i in range(1, ArraySize-1):
            ##########################################
            #### End of question P3.4
            ## Obtain the value of the summatory (T4) for the different solvers.
            ## This value will be the same irrespective of the selected discretization.
            if solver == 'Jacobi':
                summatory = aij*(uCurrent[i+1] + uCurrent[i-1])
            elif solver == 'Gauss-Seidel':
                summatory = aij*(uNext[i-1] + uCurrent[i+1])
            else:
                raise ValueError("Solver not implemented")
            #### End of question P3.4
            ##########################################

            ##########################################
            #### Question P3.5
            ## Obtain the value of the b term for the different discretizations. This 
            ## value will be the same irrespective of the solver
            
            if discretization == 'Implicit':
                    
                b[i] = 2* array[StateTemperature][i]-array_previous[StateTemperature][i]
            
            elif discretization == 'Crank-Nicolson':
                
                m_jplus = mu*array[StateTemperature][i+1]
                
                m_j = 2*(1-mu)*array[StateTemperature][i]
                
                m_j_minus = mu*array[StateTemperature][i-1]
                
                m_minus_j = array_previous[StateTemperature][i]
                
                b[i] = m_jplus + m_j + m_j_minus - m_minus_j
            
            else:
                raise ValueError("Discretization not implemented")
            #### End of question P3.5
            ##########################################
            
            ##########################################
            #### Question P3.6
            ## Implement Jacobi/Gauss-Seidel forumla. Given the above computations of 
            ## P3.4 and P3.5, the implementation should be the same for both cases
            
            uNext[i] = (b[i]-summatory)/aii
            
            #### End of question P3.6
            ##########################################
        # Calculate the error of u^{(m+1),(n+1)} with respect to u^{(m+1),(n)} 
        error = ComputeError(uCurrent, uNext)
        # If the error is less than the threshold, then break the loop
        if error <= threshold: 
            print("Error < threshold. Stopping at {} iterations...".format(iteration+1))
            break
        
        ##############################################
        #### Question P3.7
        # Update the boundaries for u^{(m+1),(n+1)} using Neumann
        EnforceBoundaryConditions(uNext)


        # Update u^{(m+1),(n)} with the obtained u^{(m+1),(n+1)}
        for element in range (ArraySize):
            uCurrent[element] = uNext[element]
        
        #### End of question P3.7
        ##############################################


    # After-solver: printing the number of executed iterations, in case error > threshold
    if error > threshold:
        print("Executed the pre-specified {} iterations. Stopping...".format(maxIterations))

    ##################################################
    #### Question P3.8
    ## Post-solver cleanup. 
    # 1. Copy the current state into the previous state by:
    # 1.1 Updating the position
    for i in range (ArraySize):
        array_previous[StateTemperature][i] = array[StateTemperature][i]
    # 1.2 Updating the time
    array_previous[StateTime] += delta_t
    # 2. Copy the result of the solver into the current state by:
    # 2.1 Updating the position
    for i in range (ArraySize):
        array[StateTemperature][i]  = uNext[i] 
    # 2.2 Updating the time
    array[StateTime] += delta_t
    # 3. Enforce boundary conditions on u^{m}
    EnforceBoundaryConditions(array[StateTemperature])
    
    
    
    
    #### End of question P3.8
    ##################################################



######################################################
def DrawState():
    # Constants for visualization purposes
    PixelsPerCell   = 6
    OffsetX = 716
    OffsetY = 0.8*800
  
    for i in range(0,ArraySize):
        PixelsX = i*(PixelsPerCell-1)
        
        SimY = max(StateI_J[StateTemperature][i],0) ## Fill with the name of the index
        fill(SimY, 0.0, (1-SimY))
        rect(OffsetX-PixelsX, 250, PixelsPerCell-1, -150*SimY)

        SimY = max(StateI_GS[StateTemperature][i],0) ## Fill with the name of the index
        fill(SimY, 0.0, (1-SimY))
        rect(OffsetX-PixelsX, 450, PixelsPerCell-1, -150*SimY)

        SimY = max(StateCN_J[StateTemperature][i],0) ## Fill with the name of the index
        fill(SimY, 0.0, (1-SimY))
        rect(OffsetX-PixelsX, 650, PixelsPerCell-1, -150*SimY)

        SimY = max(StateCN_GS[StateTemperature][i],0) ## Fill with the name of the index
        fill(SimY, 0.0, (1-SimY))
        rect(OffsetX-PixelsX, 850, PixelsPerCell-1, -150*SimY)

    ## Protect the figure's name
    fill(1.0,1.0,1.0)
    rect(0.0,0.0,900-1,40)
    ## Title
    fill(0.0)
    textSize(21)
    text("Wave Equation - Implicit Methods", 10, 30)

    ## Labels
    fill(0.0)
    text("Discretization: Implicit,                Solver: Jacobi", 84, 100)
    text("Time = " + str(round(StateI_J[StateTime]*10)/10) + "s", 650,100)
    text("Discretization: Implicit,                Solver: Gauss-Seidel", 84, 300)
    text("Discretization: Crank-Nicholson, Solver: Jacobi", 84, 500)
    text("Discretization: Crank-Nicholson, Solver: Gauss-Seidel", 84, 700)

def draw():
    background(0.9)

    TimeStep(StateI_J,StateI_J_previous,'Implicit','Jacobi')
    TimeStep(StateI_GS,StateI_GS_previous,'Implicit','Gauss-Seidel')
    TimeStep(StateCN_J,StateCN_J_previous,'Crank-Nicolson','Jacobi')
    TimeStep(StateCN_GS,StateCN_GS_previous,'Crank-Nicolson','Gauss-Seidel')

    print("")
    DrawState()
