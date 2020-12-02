;1 reverse duplicate
(define (reverseDup lst) 
    (let ((r (reverse lst)))
        (append r r)))

;2. binpow
(define (binpow a b)
    (if (zero? b) 
        1
        (let ((c (binpow a (quotient b 2))))
                (if (zero? (remainder b 2))
                    (* c c)
                    (* a c c)))))


;3. fibonacci
(define (fib n)
   (let loop
      ((m 0)
       (k 1)
       (count n))
      (if (= count 0)
        m
        (loop k (+ m k) (- count 1)))))



;4. list partition
(define (partition n lst)
    (if (null? lst) 
        '(() ())
        (let ((splitRest (partition n (cdr lst))))
            (if (< (car lst) n)
                (list 
                    (cons (car lst) (car splitRest))
                    (cadr splitRest))
                (list 
                    (car splitRest) 
                    (cons (car lst) (cadr splitRest)))))))


