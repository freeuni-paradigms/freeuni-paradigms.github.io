"""
1. გაუცვალეთ ორ ცვლადს მნიშვნელობები
"""
a = 1
b = 2

a, b = b, a

"""
2. შეატრიალეთ ლისტი
"""
lst = [1, 2, 3, 4, 5, 6]

reversed_lst = lst[::-1]

"""
3. შეამოწმეთ არის თუ არა რიცხვი პალინდრომი
"""
number = 798
reversed_number = int(str(number)[::-1])
is_palindrome = number == reversed_number

"""
4. დაწერეთ ქუიქ სორტის ალგორითმი
"""
def quicksort(sequence):
    if (len(sequence) == 0): return sequence
    front = quicksort([le for le in sequence[1:] if le <= sequence[0]])
    back = quicksort([gt for gt in sequence[1:] if gt > sequence[0]])
    return front + [sequence[0]] + back

"""
5. მოცემულია n და k დაწერეთ ფუნცია რომელიც დააბრუნებს k-ს პირველ n ხარისხს
"""
def generate_powers(n, k):
    return list(map(lambda x: k ** x, range(1, n + 1)))

"""
6. მოცემულია ლისტი და ელემენტი დაწერეთ ფუნქცია რომელიც დააბრუნებს ლისტში რომელ ინდექსებზე გვხვდება ეს ელემენტი
"""
def elem_indexes(lst, elem):
    return [i for i in range(len(lst)) if elem == lst[i]]
