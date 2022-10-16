# TODO
def main():
    # prompt user for valid input
    def get_cents():
        while True:
            try:
                cents = float(input("Amount Owed: "))
                cents = cents * 100
                if cents >= 0:
                    break
            except:
                print("not a valid input")
        return cents
    #  store user input in cents
    cents = get_cents()
    # calculate the amount of quarters in cents and keep track of remaining
    quarters = calc_quarters(cents)
    cents = cents - (quarters * 25)
    # calculate the amount of dimes in cents and keep track of remaining
    dimes = calc_dimes(cents)
    cents = cents - (dimes * 10)
    # calculate the amount of nickels in cents and keep track of remaining
    nickels = calc_nickels(cents)
    cents = cents - (nickels * 5)
    # calculate the amount of pennies in cents and keep track of remaining
    pennies = calc_pennies(cents)
    cents = cents - (pennies * 1)
    # calculate total coins and print
    coins = int(quarters + dimes + nickels + pennies)
    print(coins)


def calc_quarters(cents):
    return int(cents / 25)


def calc_dimes(cents):
    return int(cents / 10)


def calc_nickels(cents):
    return int(cents / 5)


def calc_pennies(cents):
    return cents


if __name__ == "__main__":
    main()