
run:	dequedriver.cpp Deque.h Deque.cpp DoublyLinkedList.h DoublyLinkedList.cpp Node.h Node.cpp
		g++ Deque.cpp dequedriver.cpp DoublyLinkedList.cpp Node.cpp -o dequedriver

test:	
		./dequedriver < test01
		@echo 
		./dequedriver < test02
		@echo 
		./dequedriver < test03
		@echo
		./dequedriver < test04
		@echo 

clean:
		-rm dequedriver 



