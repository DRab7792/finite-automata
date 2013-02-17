rabinowitz: driver

driver: driver.cpp fa.h fa.cpp
	g++ -o rabinowitz driver.cpp fa.h fa.cpp

clean:
	rm -f *.o rabinowitz 
