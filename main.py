import re

def check_idnp(idnp):
    if idnp is None or idnp == "":
        return False

    pattern = r'\d{13}'
    regex = re.compile(pattern)
    match = regex.match(idnp)

    if not match:
        return False

    char_idnp = list(idnp)

    int_sum1 = 0
    int_sum2 = 0
    int_sum3 = 0
    
    for i in range(0, len(idnp) - 1, 3):
        int_sum1 += int(char_idnp[i])
        int_sum2 += int(char_idnp[i + 1])
        int_sum3 += int(char_idnp[i + 2])

    return idnp.endswith(str((int_sum1 * 7 + int_sum2 * 3 + int_sum3) % 10))

def main():
    idnp = "1234567891234"
    idnp_valid = check_idnp(idnp)

    if idnp_valid:
        print("Valid IDNP")
    else:
        print("Not a valid IDNP")

if __name__ == "__main__":
    main()