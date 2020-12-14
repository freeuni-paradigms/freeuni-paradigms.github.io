"""
დაწერეთ map-ის იმპლემენტაცია და მისი გამოყენებით დაწერეთ ორი ამოცანა
1. გადმოგეცემათ რიცხვების ლისტი და ამ ლისტებისთვის დააბრუნეთ სია სადაც ეწერება True თუ რიცხვი ლუწია და False თუ კენტია
2. გადმოგეცემათ რიცხვების ლისტი და ამ ლისტებისთვის დააბრუნეთ სია სადაც ეწერება False თუ რიცხვი ლუწია და True თუ კენტია
"""
def my_map(func, lst):
    new_lst = []
    for elem in lst:
        res = func(elem)
        new_lst.append(res)
        
    return new_lst

def is_even(number):
    return number % 2 == 0

def is_odd(number):
    return number % 2 == 1

print(my_map(is_even, [1, 2, 3, 4, 5, 6]))
print(my_map(is_odd, [1, 2, 3, 4, 5, 6]))

"""
შიდა ფუნქციები.
რას დაბეჭდავს parent() ფუნქცია
"""
def parent():
    print("Printing from the parent() function")

    def first_child():
        print("Printing from the first_child() function")

    def second_child():
        print("Printing from the second_child() function")

    first_child()
    second_child()
    
parent()


"""
დაწერეთ ფუნქცია რომელიც დააბრუნებს ფუნქციას რომელიც ამოწმებს რიცხვის ლუწობას თუ გადავცემთ პარამეტრად "EVEN"-ს და
დააბრუნებს ფუნქციას რომელიც ამოწმებს რიცხვის კენტობას თუ გადავცემთ პარამეტრად "ODD"-ს
"""
def func(param):
    if param == "EVEN":
        return is_even
    if param == "ODD":
        return is_odd
    
"""
დაწერეთ მარტივი დეკორატორი რომელიც ფუნქციის დაწყებისას დაბეჭდავს დაწყების დროს და დასრულებისასაც დაბეჭდავს დასრულების დროს და რამდენ ხანში დასრულდა
"""
import time

def just_sleep():
    time.sleep(2)

def decorator(func):
    
    def wrapper():
        start = time.time()
        print(f"Start: {start}")
        func()
        end = time.time()
        print(f"End: {end}")
        print(f"Elapsed: {end - start}")
        
    return wrapper

just_sleep = decorator(just_sleep)
just_sleep()


@decorator
def just_sleep():
    time.sleep(2)
    
just_sleep()

"""
დაწერეთ დეკორატორი რომელიც ორჯერ გამოიძახებს ფუნქციას
"""
def do_twice(func):
    
    def wrapper():
        func()
        func()
        
    return wrapper

@do_twice
def hello():
    print("Hello!")

hello()

"""
დაწერეთ ფუნქცია რომელსაც გადაეცემა n და აბრუნებს ფიბონაჩის მიმდევრობის n-ურ წევრს
"""
def memoize(func):
    memo = {}
    def helper(x):
        if x not in memo:            
            memo[x] = func(x)
        return memo[x]
    return helper

@memoize
def fib(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fib(n-1) + fib(n-2)
 
