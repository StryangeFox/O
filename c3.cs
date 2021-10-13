using System;
 
namespace Shapes
{
    abstract class Figure
    {
        public abstract string Area();
        public abstract string ShapeName();
 
        public void ShowInfo()
        {
            Console.WriteLine(
                $"Название фигуры: {ShapeName()}\n" +
                $"Площадь: {Area()}\n"
                );
            Console.WriteLine();
        }
    }
 
    class Triangle : Figure
    {
        double sideA, sideB, sideC;   // Стороны треугольника
 
        // Конструктор
        public Triangle(double triangleSideA, double triangleSideB, double triangleSideC)
        {
            SideA = triangleSideA;
            SideB = triangleSideB;
            SideC = triangleSideC;
        }
 
        // Свойство, проверяем значение на отрицательность.
        // Если значение отрицательное меняем его на аналогичное положительное.
        public double SideA
        {
            get { return sideA; }
            set { sideA = value < 0 ? -value : value; }
        }
 
        public double SideB
        {
            get { return sideB; }
            set { sideB = value < 0 ? -value : value; }
        }
 
        public double SideC
        {
            get { return sideC; }
            set { sideC = value < 0 ? -value : value; }
        }
 
        // Метод для вычисления площади треугольника
        public override string Area()
        {
            double semPer = (sideA + sideB + sideC) / 2;
            return Math.Sqrt(semPer * (semPer - sideA) * (semPer - sideB) * (semPer - sideC)).ToString();
        }
 
        // Метод возвращающий наименование фигуры
        public override string ShapeName()
        {
            return "Треугольник";
        }
    }
 
    class Square : Figure
    {
        double side;   // Сторона квадрата
 
        // Конструктор
        public Square(double squareSide)
        {
            Side = squareSide;
        }
 
        // Свойство, проверяем значение на отрицательность.
        public double Side
        {
            get { return side; }
            set { side = value < 0 ? -value : value; }
        }
 
        // Метод для вычисления площади квадрата
        public override string Area()
        {
            return (side * side).ToString();
        }
 
        // Метод возвращающий наименование фигуры
        public override string ShapeName()
        {
            return "Квадрат";
        }
    }
 
    class Rectangle : Figure
    {
        double width;   // Ширина прямоугольника
        double height;   // Высота прямоугольника
 
        // Конструктор
        public Rectangle(double rectangleWidth, double rectangleHeight)
        {
            Width = rectangleWidth;
            Height = rectangleHeight;
        }
 
        // Свойство, проверяем значение на отрицательность.
        public double Width
        {
            get { return width; }
            set { width = value < 0 ? -value : value; }
        }
 
        public double Height
        {
            get { return height; }
            set { height = value < 0 ? -value : value; }
        }
 
        // Метод для вычисления площади прямоугольника
        public override string Area()
        {
            return (width * height).ToString();
        }
 
        // Метод возвращающий наименование фигуры
        public override string ShapeName()
        {
            return "Прямоугольник";
        }
    }
 
    class Program
    {
        static void Main()
        {
            Console.WriteLine("Треугольник со сторонами 4, 5, 6");
            Figure figure1 = new Triangle(4, 5, 6);
            figure1.ShowInfo();
            Console.WriteLine("Квадрата со сторонами 4");
            Figure figure2 = new Square(5);
            figure2.ShowInfo();
            Console.WriteLine("прямоугольник со сторонами 5, 6");
            Figure figure3 = new Rectangle(5, 6);
            figure3.ShowInfo();
 
            Console.ReadKey();
        }
    }
}