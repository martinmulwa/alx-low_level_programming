#!/usr/bin/python3

def is_palindromic(n):
	return str(n) == str(n)[::-1]


n = 3
u = 10 ** n - 1
l = 10 ** (n - 1) - 1
num = 0
i = u
for i in range(u, l, -1):
	if i % 11 == 0:
		num = i
		break

palindromes = []
for i in range(num, l, -11):
	for j in range(u, l, -1):
		if is_palindromic(i * j):
			palindromes.append(i * j)

print(max(palindromes), end="")
