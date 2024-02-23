function c() {
  oj-bundle main.cpp > bundle.cpp
  gcc -std=c++20 -O2 -I/workspaces/compro/ac-library bundle.cpp
}

function a() {
  ./a.out
}
