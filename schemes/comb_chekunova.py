import itertools
from itertools import permutations

#размещения с повторениями
def placements_with_repetitions(n, k):
  ans = set()
  elements = [i for i in range(1, n+1)]
  placements = itertools.product(elements, repeat = k)
  for placement in placements:
    ans.add(placement)
  return ans

#размещения без повторений
def placements_without_repetitions(n, k):
  ans = set()
  arr = list(range(1, n + 1))
  unique_permutations = set(permutations(arr, k))
  for perm in unique_permutations:
    ans.add(perm)
  return(ans)




