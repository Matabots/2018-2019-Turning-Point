import os.path

#The last line after the introduction
Line_Break = "###2018-2019-Turning-Point\n"
#Last line of List
List_End = "**=====================**\n"
#Github local repository path
GH_REPO_PATH = '/Users/pablolepe/Documents/College/CSUN/Clubs/Vex Robotics/Programming/2018-2019/Code/2018-2019-Turning-Point/'
#Github local + name of markdown
GH_ToC_PATH = os.path.join(GH_REPO_PATH, 'README.md')

# inputFile = open('Repo_Index.txt', "r")

#reads the intro lines and skips them
# x = 0
start = 0
end = 0
old_file_Lines = []
new_file_Lines = []
output_file_Lines = []
Pre_List = ["NULL"]
Post_List = ["NULL"]

#reads new list
with open('Repo_Index.txt', "r") as input:
    for line in input:
        line.strip() #cleans line of extra whitespace
        new_file_Lines.append(line)

#reads old list
with open(GH_ToC_PATH, "r") as oldF:
    for oldLine in oldF:
        oldLine.strip()
        old_file_Lines.append(oldLine)

for t in new_file_Lines:
    print(new_file_Lines)
    print("\n")

for s in old_file_Lines:
    print(old_file_Lines)
    print("\n")

#reads old file for input area
for x in range(0, len(old_file_Lines)):
    if (old_file_Lines[x] == Line_Break):
        start = x
    if (old_file_Lines[x] == List_End):
        end = x

print("Starting line is: ")
print(start)
print("Ending line is: ")
print(end)
    #saves the lines before the list
    # if (x < start):
    #     if (x == 0):
    #         Pre_List.insert(1, newLine)
    #         Pre_List.remove("NULL")
    #saves the lines after the list
    # if (x > end):
    #     if (x == (end + 1)):
    #         Post_List.insert(1, newLine)
    #         Post_List.remove("NULL")

#places output file lines nefore list
for y in range(0, (start + 1)):
    output_file_Lines.insert(y,old_file_Lines[y])
    print(output_file_Lines[y])

#adds new output file lines for list
for z in range(0, len(new_file_Lines)):
    #the first and second chars is always "|-"
    # if (new_file_Lines[z][2] != '-')
    #     newLine = "**"
    done = 0
    newLine = ""
    for n in range(3,(len(new_file_Lines[z]))):

        if (new_file_Lines[z][n] != "-"):
            if(done == 0):
                for p in range(2, n):
                    if (p == 2):
                        newLine = newLine + "##"
                    else:
                        newLine = newLine + "#"
                done = 1
                newLine = newLine + new_file_Lines[z][n]
            else:
                newLine = newLine + new_file_Lines[z][n]

        else:
            newLine = newLine + "."
    done = 0
    output_file_Lines.append(newLine + "\n")
    print(output_file_Lines[z])
#start + (len(new_file_Lines))
for a in range(end,len(old_file_Lines)):
    output_file_Lines.append(old_file_Lines[a])
    print(output_file_Lines[a])


#reads lines and puts them into markdown syntax for README.md

# input.close()
output = open(GH_ToC_PATH, "w")
for b in range(0, (len(output_file_Lines))):
    output.write(output_file_Lines[b])
output.close()
