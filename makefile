all:stl stdio

stl:stl.cpp
	g++ stl.cpp -o stl.exe

stdio:stdio.cpp
	g++ stdio.cpp -o stdio.exe

a1012:a1012.cpp
	g++ a1012.cpp -o a1012.exe
