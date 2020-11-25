1.
(define (filter-range lst a b)
    (if (null? lst) '()
        (if (and (<= a (car lst)) (>= b (car lst))) (cons (car lst) (filter-range (cdr lst) a b))
            (filter-range (cdr lst) a b)
        )
    )
)

2.
(define (k-th-element lst k)
    (if (null? lst) "None"
        (if (zero? k) (car lst) 
            (k-th-element (cdr lst) (- k 1))
        )
    )
)

3.
(define (helper n k)
    (if (equal? k 1) #t
        (if (zero? (remainder n k)) #f
            (helper n (- k 1))
        )    
    )
)

(define (prime? n)
    (if (equal? n 1) #f
        (helper n (- n 1))
    )
)

