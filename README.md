# SimpleConsoleRegistration

This C++ Program runs a Console Application for registering and logging in users. User Information is saved in a file after registration.

## Problem(s)

This Program needs to solve these Problems.
Provide a console menu.
Register an User.
Login an User.

### Console Menu

When the user runs this program, the user needs to decide to login, register or exit the program

- Solution:
- Print a Text:
- Get User Input
- Check if user Input Equals Number for registration, login or exit.
- 0 for Registration
- 1 for login
- 9 for exit
  The menu shall be run in a loop so the user can exit the program only when Ctrl + C or with the Key 9.

### Registration

When the user chooses registration an Username and Password shall be selected
The Username and password shall be saved in a textfile in unencrypted form.

- Solution:
- Print a Text to ask for Username:
- Get Username Input:
- Check if username is a valid text and username does not exist. If they do repeat this step
- Get Password input:
- Check if password is valid. if not repeat this step
- Open login file. If it does not exist create
- Append Username and password into file
- Return to Console Menu

### Login

When the user chooses login. An username and password shall be provided by the user.
If Username and password exist in login file and match. The user shall see a console Output you are now logged in as User X.

- Solution
- Print a Text to ask for Username:
- Get Username Input:
- Get Password input:
- Open Login file.
- In a loop:
  -- Check if username matches
  -- If yes also check if password matches
  -- Return succesful login
- IF end of loop and no match found return error
- Return to console menu

### Breakdown

When we break down the bigger problems we have the following smaller problems:

- Printing the Menu
- Getting an UserInput
- Check if a file exists
- Open a File
- Create a File
- Append to a File
- Read a file
- Read a file line by line
- Close a file
- Get login credentials
- Add Login credentials
- Check login credentials

### Solution Components/Modules

The Solution can be broken down into the following Modules, with the following operations:
-File-IO contains File-Operations. Here the fstream Library can be used.

- checkFileExists()
- open()
- create()
- append()
- read()
- readLine()
- close()
  -User-IO contains User-Operations.
- printMenu()
- getUserInput()
  -Auth-Model contains Registration and Login Operations
- getLoginCredentials()
- addLoginCredetnails()
- checkLoginCredentials()
- checkUsernameExists()
