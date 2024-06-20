package main

func func1(a int) int {
  return 2
}

func main(){
  for i:=0; i<100000000; i++ {
    func1(1)
  }
}