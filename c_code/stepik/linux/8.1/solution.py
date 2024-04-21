import sys
import getopt

def main(argv):
    try:
        opts, args = getopt.getopt(argv, "q:iv", ["query=", "longinformationrequest", "version"])
    except getopt.GetoptError:
        print("-")
        sys.exit(1)

    for opt, arg in opts:
        if opt in ("-q", "--query"):
            pass  
        elif opt in ("-i", "--longinformationrequest"):
            pass  # Обработка опции -i
        elif opt in ("-v", "--version"):
            pass  # Обработка опции -v

    print("+")

if __name__ == "__main__":
    main(sys.argv[1:])
