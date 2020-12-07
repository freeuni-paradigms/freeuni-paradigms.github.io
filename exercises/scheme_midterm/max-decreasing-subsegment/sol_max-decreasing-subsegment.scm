(define (last-element seq)
  (if (= (length seq) 1)
      (car seq)
      (last-element (cdr seq))))

(define (is-greater-list? a b)
  (cond ((null? a) #t)
	((> (car a) (car b)) #t)
	((< (car a) (car b)) #f)
	(else (is-greater-list? (cdr a) (cdr b)))))

(define (list-max a b)
  (cond ((> (length a) (length b)) a)
	((< (length a) (length b)) b)
	((is-greater-list? a b) a)
	(else b)))

(define (helper left right)
  (cond ((null? right) left)
	((null? left)
	 (helper (list (car right)) (cdr right)))
	((> (last-element left) (car right))
	 (helper (append left (list (car right)))
		 (cdr right)))
	(else
	 (list-max
	  left
	  (helper (list (car right)) (cdr right))))))

(define (max-decreasing-subsegment sequence)
  (helper '() sequence))



----------------------------------------------------------------
(define (last-elem lst)
  (if (null? (cdr lst)) (car lst)
    (last-elem (cdr lst))
  )
)

(define (push-back sequence elem)
  (append sequence (list elem))
)

(define (get-result-equal a b)
  (cond ((null? a) #t)
	((> (car a) (car b)) #t)
	((< (car a) (car b)) #f)
	(else (get-result-equal (cdr a) (cdr b))))
)

(define (get-result curr-mds curr-result)
  (if (> (length curr-mds) (length curr-result)) curr-mds
    (if (< (length curr-mds) (length curr-result)) curr-result
      (if (get-result-equal curr-mds curr-result) curr-mds
        curr-result
      )
    )
  )
)

(define (mds-rec sequence curr-mds curr-result)
  (if (null? sequence) curr-result
    (if (> (last-elem curr-mds) (car sequence)) (mds-rec (cdr sequence) (push-back curr-mds (car sequence)) (get-result (push-back curr-mds (car sequence)) curr-result))
      (mds-rec (cdr sequence) (list (car sequence)) (get-result curr-result (list (car sequence))))
    )
  )
)

(define (max-decreasing-subsegment sequence)
  (mds-rec (cdr sequence) (list (car sequence)) (list (car sequence)))
)
