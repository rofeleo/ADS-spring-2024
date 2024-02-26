# размещения с повторениями
def placements_with_repetitions(n, m):
  ans = set()
  elements = [str(i) for i in range(1, n+1)]
  placements = itertools.product(elements, repeat = m)
  for placement in placements:
    ans.add((''.join(placement)))
  return ans

#print(len(placements_with_repetitions(5, 3)))
