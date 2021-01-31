# heterogeneous_priority_queue    
 თქვენი ამოცანაა დაწეროთ ჰეტეროგენული პრიორიტეტული რიგი. მასში ჩვეულებრივი პრიორიტეტული რიგისგან განსხვავებით, შეიძლბა სხვადასხვა ტიპის ელემენტების ჩამატება. ფუნქციები, რომელთა იმპლემენტაციაც საჭიროა მოცემულია heterogeneous_priority_queue.h ფაილში. პრიორიტეტულ რიგში ელემენტები ემატება პრიორიტეტების ზრდის მიხედვით. თუ ელემენტების პრიორიტეტები ემთხვევა, ფუნქციამ ახალი ელემენტი უნდა დაამატოს ერთნაირი პრიორიტეტების მქონე ელემენტების ბოლოში.    
მაგ.:  
int n = 4;  
PQueuePush(&p, &n, sizeof(int), 3);  
char a = 'a';  
PQueuePush(&p, &a, sizeof(char), 2);  

PQueuePop(&p) დააბრუნებს 'a'-ს მიმთითებელს.  
PQueuePop(&p) დააბრუნებს 4-ის მიმთითებელს.


