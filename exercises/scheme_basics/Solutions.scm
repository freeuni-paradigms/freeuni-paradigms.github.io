1. 
(define (first-elem lst)
    (if (null? lst) "None"
    (car lst))
)

2. 
(define (abs n)
    (if (negative? n) (- 0 n) n)
)

3. 
(define (right-triangle? lst)
    (if (equal? (+ (expt (car lst) 2) (expt (cadr lst) 2)) (expt (caddr lst) 2)) #t 
    #f)
)

(define (right-triangle? lst)
    (equal? (+ (expt (car lst) 2) (expt (cadr lst) 2)) (expt (caddr lst) 2))
)

4.
(define (last-elem lst)
    (if (null? lst) "None"
        (if (null? (cdr lst)) (car lst)
            (last-elem (cdr lst)))
    )
)