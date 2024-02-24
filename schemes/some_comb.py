import itertools

# сочетания без повторений
def combinations(n, k):
  ans = set()
  for i in itertools.combinations(range(1, n + 1), k):
    ans.add(i)
  return ans


# перестановки с повторениями и без. В случае, если повторений нет, cnt имеет вид [1, 1, 1, ..., 1] - n единиц.
def permut(cnt):
  ans = set()
  nums = []
  for i in range(len(cnt)):
    for j in range(cnt[i]):
      nums.append(i + 1)
  for i in itertools.permutations(nums, len(nums)):
    ans.add(i)
  return ans


# сочетания с повторениями
def combinations_rep(n, k):
  ans = set()
  for i in itertools.combinations_with_replacement(range(1, n + 1), k):
    ans.add(i)
  return ans

  
