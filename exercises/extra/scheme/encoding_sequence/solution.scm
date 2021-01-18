(define (helper counter sequence)
	(cond 
		((null? sequence) '())
		((= (length sequence) 1) (list (list counter (car sequence))))
		((not (equal? (car sequence) (cadr sequence))) (cons (list counter (car sequence)) (helper 1 (cdr sequence))))
		(else (helper (+ counter 1) (cdr sequence)))))


(define  (encode-sequence sequence) 
	(helper 1 sequence))