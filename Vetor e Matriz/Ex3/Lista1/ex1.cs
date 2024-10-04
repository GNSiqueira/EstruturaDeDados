using System;
class ex1
{
    static void Main()
    {
        
        Random n = new Random();

        int[] vetor1 = new int[5];
        int[] vetor2 = new int[5];
        int[] vetor3 = new int[5];

        for (int i = 0; i < vetor1.Length; i++)
        {

            vetor1[i] = n.Next(5);

        }
        for (int i = 0; i < vetor2.Length; i++)
        {

            vetor2[i] = (short)n.Next(5);

        }
        for(int i = 0;i < vetor1.Length; i++)
        {

            vetor3[i] = vetor1[i] + vetor2[i];

        }
        Console.WriteLine("Primeiro Vetor: " + string.Join(" - ", vetor1));
        Console.WriteLine("Segundo Vetor: " + string.Join(" - ", vetor2));
        Console.WriteLine("Soma dos Vetores: " + string.Join(" - ", vetor3));

    }
}
