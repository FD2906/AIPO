# Read and write I/O test using read and write method in teleportation.py
import string

def processInput():
    file_in = open('words.in')
    userInput = file_in.read()
    userInput = (userInput[1:-1]) # remove square brackets
    splitStr = userInput.split("', ") # splits string array by comma
    returnArray = []

    for index in range(len(splitStr)):
        if index == len(splitStr)-1:
            lastStr = (splitStr[index])[1:-1]
            returnArray.append(lastStr)
            break
        newStr = (splitStr[index])[1:]
        returnArray.append(newStr)
    # adds all strings to new list object

    return returnArray


def longest(array):
    newArray = [val.translate(str.maketrans('', '', string.punctuation)) for val in array]
    longestStr = max(newArray, key=len)
    stringIndex = newArray.index(longestStr)
    
    ls = array[stringIndex] # output 1
    print(ls)

    lsSplit = ls.split(" ")
    lw = max(lsSplit, key=len)
    
    occurencesCounter = lsSplit.count(lw)
    if occurencesCounter == 1: # output 2
        print(lw, file = open('words.out', 'w'))
    else:
        print(lw[::-1], file = open('words.out', 'w'))

# testArray1 = ['i am a', 'i am a contestant', 'i am a contestanb']
# testArray2 = ['welcome', 'welcome to UCC', 'welcome to UCC, welcome']

#longest(testArray1)

# Output:
# i am a contestant
# contestant

#longest(testArray2)

# Output:
# welcome to UCC, welcome
# emoclew

wordsArray = processInput()
longest(wordsArray)

# Submissions message: 'Execution failed because the return code was non zero.'
