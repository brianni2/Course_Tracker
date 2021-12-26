# Course_Tracker

This is a simple application which currently reads from a file, calculates your grades, and then displays it in a neat table format. The program is still a WIP, so functionality is very limited.

To start, list the names of your courses inside "Courses.txt", each on a new line(the program is case sensitive so any capitalization noted here is intentional and currently madatory). 

Next, create a new text file named whatever your course name is (so if the course you listed is "Math 373", then the file should be "Math 373.txt"). Inside this file, you should type out your assignments as:
[CATEGORY] WEIGHT GRADE
such that the category is of {HW, QUIZ, TEST, PROJECT, MISC} and the weight and grade are positive numbers. For instance:
HW 30 100
HW 30 97.7
TEST 15 63
QUIZ 10 58.33

Next, simply launch the program and type in the name of the course you want your grade calculated, and you're done!

I've included a sample course for you, so feel free to just make copies of it for format.
In the future, I plan for this to be much more dynamic (creating courses and assignments inside of the program, more functional main menu, etc) and with more functionality (GUI, calendar, etc).