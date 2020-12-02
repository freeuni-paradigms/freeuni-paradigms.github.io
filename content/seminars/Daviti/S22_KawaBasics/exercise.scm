; (load "exercise.scm")

(define (kthElem lst k)
    (if (null? lst)
        "None"
        (if (equal? 0 k)
            (car lst)
            (kthElem (cdr lst) (- k 1)))    
    )
)

(define (helper n k)
    (if (equal? n k)
        #t
        (if (zero? (remainder n k))
            #f
            (helper n (+ k 1))
        )
    )
)

(define (prime? n)
    (if (equal? 1 n)
    #f
    (helper n 2)
    )
)


(define (primeList lst)
    (if (null? lst)
        '()
        (cons (prime? (car lst)) (primeList (cdr lst)))
    )
)

(define (primes? lst)
    (map prime? lst)
)

(define (power n)
    (if (zero? n)
        1
        (* 2 (power (- n 1)))
    )
)

(define (rangeHelper k i)
    (if (> i k)
        '()
        (cons i (rangeHelper k (+ i 1)))
    )
)

(define (range k)
    (if (zero? k)
        '()
        (rangeHelper k 1)
    )    
)


(define (generatePowers k)
    (map power (range k))
)