using System;
class ex1
{
    static void Main()
    {
        short alvo = 0;
        int[] c = new int[10];
        for (int i = 0; i < 10; i++) {
            Console.WriteLine("Digite o " +(i+1)+"°");
            c[i] = Convert.ToInt32(Console.ReadLine());
            if (c[i] == 47)
            {
                
                alvo++;

            }

        }
        Console.WriteLine(String.Join(" , ", c));

        if (alvo == 0)
        {

            Console.WriteLine("O número alvo não está no vetor!");

        }
        else
        {

            Console.WriteLine("O número alvo está no vetor!");

        }

        
        
    }
}
