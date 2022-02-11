"""
Imagine a length-N array of booleans, initially all false. Over time, some values are set to true, and at various points in time you would like to find the location of the nearest true to the right of given indices.
You will receive Q queries, each of which has a type and a value. SET queries have type = 1 and GET queries have type = 2.
When you receive a SET query, the value of the query denotes an index in the array that is set to true. Note that these indices start at 1. When you receive a GET query, you must return the smallest index that contains a true value that is greater than or equal to the given index, or -1 if no such index exists.
"""
def solve(input_arr):
#  [[2, 3], [1, 2], [2, 1], [2, 3], [2, 2]]
#  [ False   False   False  False   False ]
  state_arr = [[False] * len(input_arr)]
  output = []
  
  for array in input_arr:
    # Setting
    if array[0] == 1:
      state_arr[array[1]] = True
    # Getting
    elif array[0] == 2:
      nearest_true = None
      for i in range(array[1], len(state_arr)):
        if state_arr[i] == True:
          nearest_true = i
          break
      if nearest_true == None:
        output.append(-1)
      else:
        output.append(nearest_true)
  return output