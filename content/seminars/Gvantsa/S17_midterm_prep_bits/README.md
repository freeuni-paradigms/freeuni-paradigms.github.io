---
nav_order: 17
title: 17. შუალედურისთვის მომზადება. ბიტური ოპერაციები
parent: გვანცა
grand_parent: სემინარები
---

# გარჩეული ამოცანები
# რაგბი
რაგბის თამაშების შედეგები გვაქვს მოცემული როგორც ბაიტების მიმდევრობა. თითოეული თამაშის შედეგი წარმოდგენილია როგორც:

<გუნდის სახელი><სფეისი><ერთ ბაიტიანი ქულა პირველი გუნდის><ერთ ბაიტიანი ქულა მეორე გუნდის><სფეისი><მეორე გუნდის სახელი>

გუნდის სახელები შედგება დიდი და პატარა ლათინური ასოებისგან. თამაშის შედეგები გამოყოფილია წერტილ-მძიმეებით. ბოლოს თამაშის შედეგი წერტილ მძიმის ნაცვლად მთავრდება ‘\0’ სიბოლოთი. მაგალითად:
ascii: “a 0 2 b;b 1 0 c”
hex: 61 20 30 20 32 20 62 3b 62 20 31 20 30 20 63 00

თქვენი ამოცანაა იმპლემენტაცია გაუკეთოთ შემდეგ სამ ფუნქციას:

// Returns total number of games played by team with given name.
int TotalGamesPlayed(void* results, char* team_name);

// Returns total points scored across all games by team with given name.
int TotalPointsScored(void* results, char* team_name);

// Returns number of games won by team with given name.
int NumWins(void* results, char* team_name);

## [ამოხსნა](https://github.com/freeuni-paradigms/freeuni-paradigms.github.io/blob/master/exercises/midterms/rugby)

# კოდირება
## [პირობა](https://github.com/freeuni-paradigms/freeuni-paradigms.github.io/blob/master/exercises/midterms/decompress/readme.md)
## [ამოხსნა](https://github.com/freeuni-paradigms/freeuni-paradigms.github.io/blob/master/exercises/midterms/decompress)