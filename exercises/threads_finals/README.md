# Inverted Index

თქვენი ამოცანაა index.h ფაილში არსებული BuildInvertedIndex ფუნქციის იმპლემენტირება, რომელმაც უნდა მოახდინოს გადაცემული დოკუმენტების კონკურენტულად ინდექსირება. ინდექსირება ნიშნავს რომე ყველა დოკუმენტში არსებული ყველა სიტყვისთვის უნდა იპოვოთ თუ რომელ დოკუმენტებში რომელ პოზიციებზე გვხვდება იგი. გარანტია გაქვთ რომ დოკუმენტები შეიცავენ მხოლოდ ინგლისური ალფავიტის ასოებს და ჰარებს (space). სიყვები ერთმანეთისგან გამოიყობა ერთი ან მეტი ჰარის გამოყენებით.

მაგალითად თუ გვაქვს შემდეგი ორი დოკუმენტი:

* ინდექსით 0: "Hello World"
* ინდექსით 1: "Hello Free Uni"

მაშინ ინდექსი უნდა შეიცავდეს შემდეგ ინფორმაციას:

* Hello: (0, 0), (1, 0) აღნიშნავს რომ სიტყვა Hello გვხვდება ნულოვან დოკუმენტში ნულ პოზიციაზე და ინდექსით პირველ დოკუმენტში ასევე ნულ პოზიციაზე.
* World: (0, 6) აღნიშნავს რომ სიტყვა World გვხვდება ნულოვან დოკუმენტში მეექვსე პოზიციაზე.
* Free: (1, 6) აღნიშნავს რომ სიტყვა Free გვხვდება ინდექსით პირველ დოკუმენტში მეექვსე პოზიციაზე.
* Uni: (1, 12) აღნიშნავს რომ სიტყვა Uni გვხვდება ინდექსით პირველ დოკუმენტში ზმეთორმეტე პოზიციაზე.

void BuildInvertedIndex(int num_docs, char** documents, int num_threads, InvertedIndex* ii);

BuildInvertedIndex ფუნქციას გადაცემა:

* int num_docs: დოკუმენტების რაოდენობა
* char** documents: სტრიქონების სია სადაც თითოეული სტრიქონი აღნიშნავს ერთ დოკუმენტს
* int num_threads: ინდექსირება უნდა მოხდეს num_threads რაოდენობის ნაკადის გამოყენებით
* InvertedIndex* ii: სადაც თითოეული სიტყვისთვის უნდა ჩაიწეროს ნაპოვნი პოზიციები

გადაცემული დოკუმენტების გასუფთავება არ გევალებათ.

InvertedIndex სტრუქტურა უკვე იმპლემენტირებულია და მისი ცვლილება არ შეიძლება. მისი გამოყენებით შეგიძლიათ დაიმახსოვროთ რომელი სიტყვა რომელ დოკუმენტებში და მათში რა პოზიციებზე გვხდება. დოკუმენტის ინდექსის და მასში პოზიციის წყვილი აღიწერება როგორც DocPos სტრუქტურა, სადაც doc_id აღნიშნავს დოკუმენტის ინდექსს ხოლო position ამ დოკუმენტში პოზიციას. InvertedIndexInsert(InvertedIndex* ii, char* word, int doc_id, int position) ფუნქციის გამოყენებით შეგიძლია ინდექსში დაამატოთ თუ რომელი სიტყვა რომელ დოკუმენტში სად გვხვდება. InvertedIndex MultiMap-ის მსგავსია და ყველა დამატებულ პოზიციას იმახსოვრებს. ინვერტირებულ ინდექსში ნაპოვნ პოზიციებს რა მიმდევრობით დაამატებთ მნიშვნელობა არ აქვს. **InvertedIndex არ არის thread-safe.**

BuildInvertedIndex ფუნქციამ უნდა გამოიყენოს num_threads რაოდენობის ნაკადი დოკუმენტების ინდექსირებისთვის. ნაკადები უნდა გაეშვას BuildInvertedIndex ფუნქციიდან და თითოეულ ნაკადს შეუძლია ერთი ან მეტი დოკუმენტის დამუშავება, რა სტრატეგიით გადაანაწილებთ დოკუმენტებს ნაკადებზე თქვენი გადასაწყვეტია. BuildInvertedIndex უნდა დაელოდოს გაშვებული ნაკადების დასრულებას და საბოლოოდ მისთვის გადაცემული ii ცვლადი უნდა შეიცავდეს სრულ ინდექსს.

**ნაშრომის შეფასებაზე ზეგავლენას მოახდენს თუ როგორი სტრატეგიით დაასინქრონიზირებთ ნაკადებს ერთმანეთთან. ოპტიმალური სტრატეგია უნდა ცდილობდეს ნაკადების მაქსიმალურად დამოუკიდებლებას რათა ნაკლებად დაბლოკონ/შეუშალონ ხელი ერთმანეთს.**

### ტესტირება
ფაილების კომპილაციისთვის გაუშვით **gcc map.c index.c inverted_index.c index_test.c -lpthread** ან უფრო მოკლედ **gcc *.c  -lpthread**<br/>
ხოლო დაკომპილირებული ფაილის გასაშვებად: **a.exe**

*მეხსიერების არასწორად გამოყენების შემთხვევაში დაკარგავთ ტესტისთვის განკუთვნილი ქულის 15%-ს.*

### შეიძლება დაგჭირდეთ შემდეგი POSIX სტრუქტურები და ფუნქციები:
#### semaphore.h
* sem_t: სემაფორის ტიპის სტრუქტურა
* int sem_init(sem_t *sem, int pshared, unsigned int value); -- initializes the unnamed semaphore at the address pointed to by sem. The value argument specifies the initial value for the semaphore.
* int sem_destroy(sem_t *sem); -- destroys the unnamed semaphore at the address pointed to by sem.
* int sem_post(sem_t *sem); -- increments (unlocks) the semaphore pointed to by sem.  If the semaphore's value consequently becomes greater than zero, then another process or thread blocked in a sem_wait(3) call will be woken up and proceed to lock the semaphore.
* int sem_wait(sem_t *sem); -- decrements (locks) the semaphore pointed to by sem.  If the semaphore's value is greater than zero, then the decrement proceeds, and the function returns, immediately.  If the semaphore currently has the value zero, then the call blocks until either it becomes possible to perform the decrement (i.e., the semaphore value rises above zero), or a signal handler interrupts the call.
#### pthread.h
* pthread_t: ნაკატის ტიპის სტრუქტურა
* int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg); -- The pthread_create() function starts a new thread in the calling process.  The new thread starts execution by invoking start_routine(); arg is passed as the sole argument of start_routine().
* int pthread_join(pthread_t thread, void **retval); -- The pthread_join() function waits for the thread specified by thread to terminate.  If that thread has already terminated, then pthread_join() returns immediately.  The thread specified by thread must be joinable.
* void pthread_exit(void *retval); -- The pthread_exit() function terminates the calling thread and returns a value via retval that (if the thread is joinable) is available to another thread in the same process that calls pthread_join(3).
* pthread_mutex_t: მუტექსის ტიპის სტრუქტურა
* int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr); -- The pthread_mutex_init() function initialises the mutex referenced by mutex with attributes specified by attr. If attr is NULL, the default mutex attributes are used; the effect is the same as passing the address of a default mutex attributes object. Upon successful initialisation, the state of the mutex becomes initialised and unlocked.
* int pthread_mutex_destroy(pthread_mutex_t *mutex); -- The pthread_mutex_destroy() function destroys the mutex object referenced by mutex; the mutex object becomes, in effect, uninitialised. An implementation may cause pthread_mutex_destroy() to set the object referenced by mutex to an invalid value. A destroyed mutex object can be re-initialised using pthread_mutex_init(); the results of otherwise referencing the object after it has been destroyed are undefined.
* int pthread_mutex_lock(pthread_mutex_t *mutex); -- The mutex object referenced by mutex shall be locked by calling pthread_mutex_lock(). If the mutex is already locked, the calling thread shall block until the mutex becomes available. This operation shall return with the mutex object referenced by mutex in the locked state with the calling thread as its owner.
* int pthread_mutex_unlock(pthread_mutex_t *mutex); -- he pthread_mutex_unlock() function shall release the mutex object referenced by mutex. The manner in which a mutex is released is dependent upon the mutex's type attribute. If there are threads blocked on the mutex object referenced by mutex when pthread_mutex_unlock() is called, resulting in the mutex becoming available, the scheduling policy shall determine which thread shall acquire the mutex.
