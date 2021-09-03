#!/usr/bin/python3
import sys


def print_output(status_dict, file_size):
    arr = [200, 301, 400, 401, 403, 404, 405, 500]
    print("File size: {}".format(file_size))
    for status in arr:
        if (status_dict[status] != 0):
            print("{}: {}".format(status, status_dict[status]))


line_count = 0
file_size = 0
status_dict = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

try:
    for line in sys.stdin:
        curr_line = line.split()
        if (len(curr_line) == 9):
            file_size += int(curr_line[-1])
            status_dict[int(curr_line[-2])] += 1
            line_count += 1
            if (line_count == 10):
                line_count = 0
                status_dict = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
                print_output(status_dict, file_size)
except Exception:
    pass
finally:
    print_output(status_dict, file_size)
