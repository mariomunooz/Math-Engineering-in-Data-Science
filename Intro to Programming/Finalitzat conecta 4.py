import turtle  # importing the turtle library
import random


# This function makes the board where the users will play
def make_board(height, width):
    board = []
    for col in range(width):
        column = [0] * height
        board.append(column)
    return board


# This function print the board where the users will play
def print_board(board):
    for col in range(len(board)):
        for row in range(len(board[col])):
            print(board[col][row], end="  ")
        print(" ")

# Because our board was made as a list of columns with rows due to practical aspects
# we have to transpose the board so that users can see it correctly
def transpose2(board):
    num_rows = height
    for row in range(len(board[0])):
        for col in range(len(board)):
            print(board[col][(num_rows - 1) - row], end=" ")
        print(" ")


def ask_playing_mode():
    """This function asks to the user the playing mode"""
    print("1) Player vs Player\n2) Player vs Computer")
    playmode = None
    while playmode is None or playmode != 1 or playmode != 2:
        try:
            playmode = int(input("Choose the playing mode: "))
            if playmode == 1 or playmode == 2:
                playmode = playmode
                return playmode
            if playmode != 1 or playmode != 2:
                print("Select one playing mode available, insert 1 or 2 ")
        except:
            print("Select one playing mode available, insert 1 or 2 ")

# This function allows us check if some player wins
# that function could be used for every type of board and number of tabs
def check_if_win(board, player, tabs_connected):
    # Check column
    for col in range(width):
        for row in range(height - (tabs_connected - 1)):
            contador = 0
            for tabs in range(tabs_connected):
                if board[col][row + tabs] == player:
                    contador += 1
            if contador == tabs_connected:
                return True
    # Check rows
    for col in range(width - (tabs_connected - 1)):
        for row in range(height):
            contador = 0
            for tabs in range(tabs_connected):
                if board[col + tabs][row] == player:
                    contador += 1
            if contador == tabs_connected:
                return True
    # Check positively sloped diagonals
    for col in range(width - (tabs_connected - 1)):
        for row in range(height - (tabs_connected - 1)):
            contador = 0
            for tabs in range(tabs_connected):
                if board[col + tabs][row + tabs] == player:
                    contador += 1
            if contador == tabs_connected:
                return True
    # Check negatively sloped diagonals
    for col in range(width - (tabs_connected - 1)):
        for row in range((tabs_connected - 1), height):
            contador = 0
            for tabs in range(tabs_connected):
                if board[col + tabs][row - tabs] == player:
                    contador += 1
            if contador == tabs_connected:
                return True

# This function allows us to check if the board is full
def full_board(board, height, width):
    full_column = 0
    for col in range(width):
        full_rows = 0
        for row in range(height):
            if board[col][row] != 0:
                full_rows += 1
        if full_rows == height:
            full_column += 1
    if full_column == width:
        return True

# This function insert the number of the player on the board
def column_selected(board, col, row, player):
    try:
        board[col][row] = player
        return board
    except:
        print("The column selected is full, please select other column")

# This function detects the first empty row
def first_empty_pos(board, col):
    try:
        for row in range(height):
            if board[col][row] == 0:
                return row
    except:
        print("The column selected is full, please select other column")

# This function allows us to detect if column inserted by the user is out of range or not
def ask_column_in_range(text, width):
    correct_input = False
    while not correct_input:
        try:
            valor = int(input(text)) - 1
            if 0 <= valor <= width - 1:
                correct_input = True
                return valor
            else:
                correct_input = False
                print("Column out of range, please select one available column")

        except:
            print("Insert one number between 1 and", width)

# This function allows us to detect when one column is full
def column_full(board, col, height):
    count = 0
    for row in range(height):
        if board[col][row] != 0:
            count += 1
    if count == height:
        full = True
    else:
        full = False
    return full


# Here is where we have been developed our game
#If you want adapt the game to diferent height, width or number of tabs, you must change these variables:
#number of tabs, inside the function playing. Height and width below when you see de comments making reference to the board properties

def playing(height, width, radius, x, y):
    board = make_board(height, width)
    tabs_connected = 4
    print("Welcome to Connect", tabs_connected)
    playmode = ask_playing_mode()
    winner = False
    full = False
    number_shifts = 0
    player = random.randint(1, 2)
    while not winner and not full:
        print("The current player is", player)
        if playmode == 1:
            if player == 1:
                color = "red"
                col_full = True
                while col_full is True:
                    col = ask_column_in_range("Player 1, choose one available column: ", width)
                    row = first_empty_pos(board, col)
                    col_full = column_full(board, col, height)
                column_selected(board, col, row, 1)
                transpose2(board)
                draw(col, row, x, y, color, radius)
                if check_if_win(board, player, tabs_connected):
                    print("Congratulations Player 1")
                    winner = check_if_win(board, player, tabs_connected)
                if full_board(board, height, width):
                    print("Game over: The board is full")
                    full = full_board(board, height, width)
                player = player % 2 + 1
            elif player == 2:
                color = "blue"
                col_full = True
                while col_full is True:
                    col = ask_column_in_range("Player 2, choose one available column: ", width)
                    row = first_empty_pos(board, col)
                    col_full = column_full(board, col, height)
                column_selected(board, col, row, 2)
                draw(col, row, x, y, color, radius)
                if check_if_win(board, player, tabs_connected):
                    print("Congratulations Player 2")
                    winner = check_if_win(board, player, tabs_connected)
                if full_board(board, height, width):
                    print("Game over: The board is full")
                    full = full_board(board, height, width)
                player = player % 2 + 1
        elif playmode == 2:
            if player == 1:
                color = "red"
                col_full = True
                while col_full is True:
                    col = ask_column_in_range("Player 1, choose one available column: ", width)
                    row = first_empty_pos(board, col)
                    col_full = column_full(board, col, height)
                column_selected(board, col, row, 1)
                transpose2(board)
                draw(col, row, x, y, color, radius)
                if check_if_win(board, player, tabs_connected):
                    print("Congratulations Player 1")
                    winner = check_if_win(board, player, tabs_connected)
                if full_board(board, height, width):
                    print("Game over: The board is full")
                    full = full_board(board, height, width)
                number_shifts += 1
                player = player % 2 + 1

            elif player == 2:
                color = "yellow"
                col_full = True
                while col_full is True:
                    if number_shifts == 0:
                        col = width // 2
                    else:
                        col = random.randint(1, width) - 1
                    row = first_empty_pos(board, col)
                    col_full = column_full(board, col, height)
                column_selected(board, col, row, 2)
                transpose2(board)
                draw(col, row, x, y, color, radius)
                if check_if_win(board, player, tabs_connected):
                    print("Congratulations Player 2")
                    winner = check_if_win(board, player, tabs_connected)
                if full_board(board, height, width):
                    print("Game over: The board is full")
                    full = full_board(board, height, width)
                number_shifts += 1
                player = player % 2 + 1



def draw(col: int, row: int, x: int, y: int, color: str, radius: int):
    col = x + 2 * radius * col
    row = y + radius + 2 * radius * row
    cursor.penup()
    cursor.setposition(col, row)
    cursor.pendown()
    cursor.dot(radius * 2, color)


def print_board_circles(height: int, width: int, x: int, y: int, cursor: int, radio: int):
    cursor.penup()
    cursor.setpos(x, y)
    cursor.pendown()
    for i in range(height):
        for j in range(width):
            cursor.circle(radio)
            cursor.penup()
            cursor.forward(radio * 2)
            cursor.pendown()
        cursor.penup()
        cursor.setpos(x, y + radio * 2 * (i + 1))
        cursor.pendown()

    # Writes the column numbers
    cursor.penup()
    cursor.setpos(x - radio * 2, y - radio)
    cursor.pendown()
    cursor.pencolor("green")
    for i in range(width):
        cursor.penup()
        cursor.forward(radio * 2)
        cursor.write(i + 1, font=("Arial", 20, "normal"))


# Main program


# Creates the window and performs some settings
window = turtle.Screen()  # creates a window to draw something
window.bgcolor("white")  # sets the background colour
window.title("Connect 4")  # sets the window title
window.setup(500, 500)  # sets he size of the window
window.reset()

cursor = turtle.Turtle()  # creates the cursor that allows us to draw
cursor.pensize(3)  # set the thickness of the cursor
cursor.pencolor("gray")  # set the colour of the cursor
cursor.speed(0)  # between 1-10

# Board Properties
height = 6
width = 7

# Coordinates where to start drawing the board
x = -150
y = -150

# Radius of the pieces
radius = 25

# Prints the board in turtle
print_board_circles(height, width, x, y, cursor, radius)

""" MAIN MENU
Here you will call the Main Menu function
"""
playing(height, width, radius, x, y)

turtle.done()
try:
    turtle.bye()
except:
    print("Game Over!")
