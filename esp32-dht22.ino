#include <stdlib.h>
#include <string>

#define N 100
#define CPUFrequency 40

#define arrayType char

arrayType array[N];

void setup()
{
  Serial.begin(9600);

  configrueCpuFrequencyMhz();

  printArrayInfo();

  execute(fillArray, "Fill Array");
  // printArray();

  execute(quickSort, "Quick Sort");
  // printArray();
}

void loop()
{
  delay(1000);
}

void fillArray()
{
  for (int i = 0; i < N; i++)
  {
    array[i] = rand() % 100;
  }
}

void printArray()
{
  for (int i = 0; i < N; i++) {
    Serial.print(array[i]);
    if (i < N - 1) {
      Serial.print(", "); // додаткова кома, якщо не останній елемент
    }
  }
  Serial.println();
}

void quickSort()
{
  quickSort(array, 0, N - 1);
}

void quickSort(arrayType arr[], int left, int right) {
  int i = left, j = right;
  arrayType pivot = arr[(left + right) / 2];

  while (i <= j) {
    while (arr[i] < pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }

    if (i <= j) {
      arrayType tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
      i++;
      j--;
    }
  }

  if (left < j) {
    quickSort(arr, left, j);
  }
  if (i < right) {
    quickSort(arr, i, right);
  }
}

void printArrayInfo()
{
  Serial.print("Array Length: ");
  Serial.println(N);

  Serial.print("Size of array: ");
  Serial.print(sizeof(array));
  Serial.println(" bytes.");
}

void execute(void (*action)(), const char* logName)
{
  double start = micros(); //повератє мікросекунди від початку запуску програми
  action();
  double end = micros();
  double executeTime = end - start;

  Serial.print("Execution time (");
  Serial.print(logName);
  Serial.print("): ");
  Serial.print(executeTime, 3); //3 - кількість знаків після коми
  Serial.println(" microseconds.");
}

void configrueCpuFrequencyMhz()
{
  setCpuFrequencyMhz(CPUFrequency);
  Serial.print("CPU Frequency(Mhz): ");
  Serial.println(getCpuFrequencyMhz());
}