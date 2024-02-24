import itertools

def combinations(n, k):
  ans = set()
  for i in itertools.combinations(range(1, n + 1), k):
    ans.add(i)
  return ans

def permut(cnt):
  ans = set()
  nums = []
  for i in range(len(cnt)):
    for j in range(cnt[i]):
      nums.append(i + 1)
  for i in itertools.permutations(nums, len(nums)):
    ans.add(i)
  return ans
