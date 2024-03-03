function c() {
  # oj-bundle -I/workspaces/compro $1 > bundle.cpp
  oj-bundle -I/workspaces/compro main.cpp > bundle.cpp
  c++ -std=c++20 -O2 -I/workspaces/compro/ac-library bundle.cpp
}

function a() {
  ./a.out
}
