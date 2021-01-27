######################################################
## Constant values for the simulations
ArraySize = 128
ConstantV = 1.5
WorldSize = 50.0
delta_t = 1.0/24.0
delta_x = WorldSize/ArraySize
##
######################################################

######################################################
#### Question PW1
##
# Your solution here
##
######################################################

######################################################
## Visualization Parameters
## Amount of pixels per cell on the X axis 
PixelsPerCell = 6

## Dimensions of the visualization window 
WindowWidth = PixelsPerCell*ArraySize
WindowHeight = WindowWidth/2
##
######################################################

######################################################
#### Question PW2
##
def approximate_ux(array):
    pass # Replace this line with the actual solution

def approximate_uxx(array):
    pass # Replace this line with the actual solution
    
##
##########################################################

def SetInitialState():
    ######################################################
    #### Question PW3
    ##
    # Your solution here
    ##
    ######################################################

def EnforceBoundaryConditions(array, index, strategy):
    ######################################################
    #### Question PW4
    ##
    #### Dirichlet boundary conditions
    if strategy == 'Dirichlet':
        pass # Replace this line with the actual solution
    ## Neumann boundary conditions
    elif strategy == 'Neumann':
        pass # Replace this line with the actual solution 
    else:
        raise ValueError("Strategy not implemented!")
    ##
    ######################################################


def setup():
    SetInitialState()
    EnforceBoundaryConditions(StateEDirichlet, StateTemperature, 'Dirichlet')
    EnforceBoundaryConditions(StateRK2Dirichlet, StateTemperature, 'Dirichlet')
    EnforceBoundaryConditions(StateENeumann, StateTemperature, 'Neumann')
    EnforceBoundaryConditions(StateRK2Neumann, StateTemperature, 'Neumann')

    size(800, 860)
    
    WindowWidth = 800
    WindowHeight = 860

    colorMode(RGB, 1.0)
    noStroke()
    textSize(24)


def TimeStepE(array, strategy):
    ##################################################
    #### Question PW5
    ##
    ## Update every state
    # Your code here

    ## Apply boundary conditions
    # Your code here
    
    ## Update simulation time.
    # Your code here
    ##
    ##################################################


def TimeStepRK2(array, strategy):
    ##################################################
    #### Question PW5
    ##
    ## Update every state
    # Your code here
    
    ## Apply boundary conditions
    # Your code here
    
    ## Update simulation time.
    # Your code here
    ##
    ##################################################


def DrawState():
    OffsetX = 716
    OffsetY = 0.8*WindowHeight
    TextBoxSize = 40

    for i in range(0,ArraySize):
        PixelsX = i*(PixelsPerCell-1)
        
        ##################################################
        #### Question PW6
        SimY = StateEDirichlet[StateTemperature][i] ## Fill with the name of the index
        fill(SimY, 0.0, (1-SimY))
        rect(OffsetX-PixelsX, 250, PixelsPerCell-1, -150*SimY)

        SimY = StateRK2Dirichlet[StateTemperature][i] ## Fill with the name of the index
        fill(SimY, 0.0, (1-SimY))
        rect(OffsetX-PixelsX, 450, PixelsPerCell-1, -150*SimY)

        SimY = StateENeumann[StateTemperature][i] ## Fill with the name of the index
        fill(SimY, 0.0, (1-SimY))
        rect(OffsetX-PixelsX, 650, PixelsPerCell-1, -150*SimY)

        SimY = StateRK2Neumann[StateTemperature][i] ## Fill with the name of the index
        fill(SimY, 0.0, (1-SimY))
        rect(OffsetX-PixelsX, 850, PixelsPerCell-1, -150*SimY)

    ## Protect the figure's name
    fill(1.0,1.0,1.0)
    rect(3.0,3.0,800-6,TextBoxSize)


def draw():
    background(0.9)

    TimeStepE(StateEDirichlet,'Dirichlet')
    TimeStepE(StateENeumann,'Neumann')
    TimeStepRK2(StateRK2Dirichlet,'Dirichlet')
    TimeStepRK2(StateRK2Neumann,'Neumann')

    DrawState()

    ## Label.
    fill(0.0)
    text("Burger's equation", 84, 32)
    text("Euler, Dirichlet", 84, 100)
    text("RK2, Dirichlet", 84, 300)
    text("Euler, Neumann", 84, 500)
    text("RK2, Neumann", 84, 700)
    
