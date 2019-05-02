temp.png: graficador.py datos.txt
	python graficador.py
datos.txt: calor.x
	./calor.x
calor.x: calor.cpp
	g++ calor.cpp -o calor.x
clean:
	rm temp.png