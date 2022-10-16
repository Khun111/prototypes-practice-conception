# TODO
# Prompt user till desired input is obtained
while True:
    try:
        h = int(input("Height: "))
        if h > 0 and h < 9:
            break
    except:
        print("That's not a valid input")
# iterate through height and print pyramid
for i in range(1, h+1):
    print(((h-i) * " "+("#" * i)))