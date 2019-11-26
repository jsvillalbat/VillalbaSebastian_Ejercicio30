evolve.png: evolve_10.dat 
	python plot.py
    
evolve_10.dat : evolve.x
	./evolve.x  > evolve_10.dat

evolve.x : evolve.cpp
	c++ evolve.cpp -o evolve.x

clean:
	rm evolve.x *.dat *.png