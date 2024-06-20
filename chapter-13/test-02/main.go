package main

func myFunction(p1, p2, p3,p4, p5 int) (int,int) {
	var a int = p1+p2+p3+p4+p5
	var b int = 3
	return a,b
}

func main() {
	myFunction(1, 2, 3, 4, 5)
}