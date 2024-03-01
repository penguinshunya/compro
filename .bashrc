function c() {
  oj-bundle -I/workspaces/compro $1 > bundle.cpp
  c++ -std=c++20 -O2 -I/workspaces/compro/ac-library bundle.cpp
}

function a() {
  ./a.out
}
