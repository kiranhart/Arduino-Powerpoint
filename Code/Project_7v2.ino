int currentNumber = 0;

int nums[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1},
  {1, 1, 1, 1, 0, 0, 1},
  {0, 1, 1, 0, 0, 1, 1},
  {1, 0, 1, 1, 0, 1, 1},
  {1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 1}
};

void setup() {
  for (int i = 2; i < 9; i++) {
    pinMode(i, OUTPUT);
  }
}

void printNumber(int index) {
  int in = 0;
  for (int i = 2; i < 9; i++) {
    digitalWrite(i, nums[index][in]);
    in += 1;
  }
}

void loop() {
  printNumber(currentNumber);

  if (currentNumber < 10) {
    currentNumber++;
    delay(1000);
  }

  if (currentNumber == 10) {
    currentNumber = 0;
    delay(1000);
  }
}
