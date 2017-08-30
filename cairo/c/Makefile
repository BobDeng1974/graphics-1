
all: cairotest.c
	gcc cairotest.c -o cairotest -I/usr/local/include/cairo -L/usr/local/lib/ -lcairo -lEGL 
	gcc blackImg.c -o blackImg -I/usr/local/include/cairo -L/usr/local/lib/ -lcairo -lEGL 
	gcc scaleImg.c -o scaleImg -I/usr/local/include/cairo -L/usr/local/lib/ -lcairo -lEGL 
	#gcc ops.c -o comp -I/usr/include/cairo -L/usr/local/lib/ -lcairo  
	#g++ compImg.cpp -o compImg -g -I/usr/include/cairo -L/usr/local/lib/ -lcairo  
	#gcc textextents.c -o textextents -I/usr/include/cairo -L/usr/local/lib/ -lcairo  
	#gcc font.c -o font -I/usr/include/cairo -L/usr/local/lib/ -lcairo  

clean:
	rm cairotest
