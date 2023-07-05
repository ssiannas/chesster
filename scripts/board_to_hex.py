teststr ="""  A B C D E F G H
1 r n b q k b n r 
2 p p - p p p p p 
3 - - - - - - - - 
4 - - p - - - - - 
5 - - - - P - - - 
6 - - - - - N - - 
7 P P P P - P P P 
8 R N B Q K B - R 
"""

def parse_str(board_str):
    board = []
    row_cnt = 0
    for row in board_str.split('\n'):
        if row_cnt == 0:
            row_cnt += 1
            continue
        board.append(row.split(' ')[1:-1])
        row_cnt += 1
    
    binstr = ""
    for row in board:
        row.reverse()
        for cell in row:
            if cell == '-':
                binstr += '0'
            else:
                binstr += '1'
    return binstr

def main():
    binstr = parse_str(teststr)
    binary = int(binstr, 2)
    hexstr = hex(binary)
    print("0x" + str(hexstr).upper()[2:] + "ULL")

    print(binstr)

if __name__ == "__main__":
    main()
