program ArrayOperations;

uses
  IntegerOperations;

var
  arr: array of integer;
  n, i, maxIndex, minIndex: integer;
  prod, sum: integer;

begin
  { Ввод количества элементов массива }
  write('Введите количество элементов массива: ');
  readln(n);

  { Инициализация генератора случайных чисел }
  Randomize;

  { Инициализация массива случайными числами }
  SetLength(arr, n);
  writeln('Массив:');
  for i := 0 to n - 1 do
  begin
    arr[i] := Random(100); { Случайное число от 0 до 99 }
    write(arr[i], ' ');
  end;
  writeln;

  { Поиск индекса наибольшего и наименьшего элементов массива }
  maxIndex := 0;
  minIndex := 0;
  for i := 1 to n - 1 do
  begin
    if arr[i] > arr[maxIndex] then
      maxIndex := i;
    if arr[i] < arr[minIndex] then
      minIndex := i;
  end;

  { Вычисление произведения наибольшего и наименьшего элементов массива }
  prod := IntegerOperations.Multiply(arr[maxIndex], arr[minIndex]);
  writeln('Произведение наибольшего и наименьшего элементов: ', prod);

  { Вычисление суммы элементов массива между наибольшим и наименьшим }
  sum := 0;
  if maxIndex < minIndex then
  begin
    for i := maxIndex + 1 to minIndex - 1 do
      sum := IntegerOperations.Add(sum, arr[i]);
  end
  else
  begin
    for i := minIndex + 1 to maxIndex - 1 do
      sum := IntegerOperations.Add(sum, arr[i]);
  end;
  writeln('Сумма элементов массива между наибольшим и наименьшим: ', sum);

  readln;
end.
