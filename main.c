#include <stdio.h>

//functions prototypes
void read_booklet(char[], char[], char[]);  //function to read all booklets data and store in arrays data structure
void read_students(char[][10], char[][30], char[][30], char[][10]); //function to read all students data
void read_answers(char[][10], char[], char[][50]); //function to read all answers data and store in arrays data structure


int main()
{

    char booklet_a[50], booklet_b[50], booklet_c[50];
    char answers_std_no[25][10], an_type[25], an_answers[25][50];
    char std_no[25][10], std_name[25][30], std_surname[25][30], std_department[25][10];

    int number_of_students = 20, answers_size = 50;//number of students, answers
    int empty_answers = 0, wrong_answers = 0, correct_answers = 0; //number of empty answers ans, correct answers, and wrong answers

    int i, j;
    int aa = 0, ab = 0, ac = 0, ad = 0, ablank = 0, count;

    int success_a = 0;
    float avarage;
    float score = 0;

    //making function calls to the different functions to read the files
    read_booklet(booklet_a, booklet_b, booklet_c);
    read_students(std_no, std_name, std_surname, std_department);
    read_answers(answers_std_no, an_type, an_answers);


    //starting preparation of the result file
    FILE *write;
    write = fopen("result.txt", "w");// open result file for writing, create if it does not exist
    fprintf(write, "PART A  (RESULTS)\n\nStd.No\t\tName&Surname\t\t\t\tDepartment\t\t  Correct\t\t  Wrong\t\t   Score\n");

    for (i = 0; i < number_of_students; i++)
    {

        if (an_type[i] == 'A')//check for 'A' answers
        {
            correct_answers = 0;
            wrong_answers = 0;
            empty_answers = 0;
            for (j = 0; j < answers_size; j++)
            {
                if (an_answers[i][j] == booklet_a[j])
                {
                    correct_answers++;

                }
                else
                {
                    if (an_answers[i][j] == '*') //check for empty answers answers
                    {
                        empty_answers++;

                    }
                    else
                    {
                        wrong_answers++;
                    }
                }

            }

        }
        else if (an_type[i] == 'B') //check for 'B' answers
        {
            correct_answers = 0;
            wrong_answers = 0;
            empty_answers = 0;
            for (j = 0; j < answers_size; j++)
            {

                if (an_answers[i][j] == booklet_b[j])
                {
                    correct_answers++;

                }
                else
                {
                    if (an_answers[i][j] == '*') //check for empty answers answers
                    {
                        empty_answers++;

                    }
                    else
                    {
                        wrong_answers++;
                    }
                }

            }
        }
        else if (an_type[i] == 'C') //check for 'C' answers
        {
            correct_answers = 0;
            wrong_answers = 0;
            empty_answers = 0;
            for (j = 0; j < answers_size; j++)
            {

                if (an_answers[i][j] == booklet_c[j])
                {
                    correct_answers++;

                }
                else
                {
                    if (an_answers[i][j] == '*') //check for empty answers answers
                    {
                        empty_answers++;

                    }
                    else
                    {
                        wrong_answers++;
                    }
                }

            }

        }

        score = (correct_answers - ((float)wrong_answers / 4)) * 2; //calculate student score
        if (score < 0)
            score = 0;
        //write to the file for part A
        fprintf(write, "%s\t\t%s %s\t\t\t\t%s\t\t\t%d \t\t\t%d \t\t\t%.2f\n", answers_std_no[i], std_name[i], std_surname[i], std_department[i], correct_answers, wrong_answers, score);//no=2,name=3mdepart=2,correcorrect_answers2,wrong_answers=2,score=2

    }

    //write to the file for part B
    fprintf(write, "\n\n\nPART B (STATISTICS)\n\n");
    fprintf(write, "BOOKLET A :\n\n");
    fprintf(write, "Questions\tCorrect Choice\tA\tB\tC\tD\tBlank\tSuccess\n");
    for (j = 0; j < answers_size; j++)
    {
        avarage = 0, count = 0, aa = 0, ab = 0, ac = 0, ad = 0, ablank = 0, success_a = 0;

        for (i = 0; i < number_of_students; i++)
        {
            if (an_type[i] == 'A')
            {
                count++;

                if (an_answers[i][j] == booklet_a[j])
                    success_a++;
                if (an_answers[i][j] == 'A')
                    aa++;
                else if (an_answers[i][j] == 'B')
                    ab++;
                else if (an_answers[i][j] == 'C')
                    ac++;
                else if (an_answers[i][j] == 'D')
                    ad++;
                else
                    ablank++;

            }
            avarage = ((float)success_a / count) * 100; //calculate the average for a student
        }

        fprintf(write, "\n%d\t\t\t%c\t%d\t%d\t%d\t%d\t%d\t%.2f%%\n", j + 1, booklet_a[j], aa, ab, ac, ad, ablank, avarage);
    }

    fprintf(write, "BOOKLET B :\n\n");
    fprintf(write, "Questions\tCorrect Choice\tA\tB\tC\tD\tBlank\tSuccess\n");
    for (j = 0; j < answers_size; j++)
    {
        avarage = 0, count = 0, aa = 0, ab = 0, ac = 0, ad = 0, ablank = 0, success_a = 0;

        for (i = 0; i < number_of_students; i++)
        {
            if (an_type[i] == 'B')
            {
                count++;
                if (an_answers[i][j] == booklet_b[j])
                    success_a++;
                if (an_answers[i][j] == 'A')
                    aa++;
                else if (an_answers[i][j] == 'B')
                    ab++;
                else if (an_answers[i][j] == 'C')
                    ac++;
                else if (an_answers[i][j] == 'D')
                    ad++;
                else
                    ablank++;

            }
            avarage = ((float)success_a / count) * 100;

        }

        fprintf(write, "\n%d\t\t\t%c\t%d\t%d\t%d\t%d\t%d\t%.2f%%\n", j + 1, booklet_b[j], aa, ab, ac, ad, ablank, avarage);
    }

    fprintf(write, "BOOKLET C :\n\n");
    fprintf(write, "Questions\tCorrect Choice\tA\tB\tC\tD\tBlank\tSuccess\n");
    for (j = 0; j < answers_size; j++)
    {
        avarage = 0, count = 0, aa = 0, ab = 0, ac = 0, ad = 0, ablank = 0, success_a = 0;

        for (i = 0; i < number_of_students; i++)
        {
            if (an_type[i] == 'C')
            {
                count++;
                if (an_answers[i][j] == booklet_c[j])
                    success_a++;
                if (an_answers[i][j] == 'A')
                    aa++;
                else if (an_answers[i][j] == 'B')
                    ab++;
                else if (an_answers[i][j] == 'C')
                    ac++;
                else if (an_answers[i][j] == 'D')
                    ad++;
                else
                    ablank++;

            }
            avarage = ((float)success_a / count) * 100;

        }

        fprintf(write, "\n%d\t\t\t%c\t%d\t%d\t%d\t%d\t%d\t%.2f%%\n", j + 1, booklet_c[j], aa, ab, ac, ad, ablank, avarage);


    }


    fclose(write);
    return 0;
}


void read_booklet(char a[], char b[], char c[])
{
    FILE * booklet;
    booklet = fopen("booklet.txt", "r");
    int i = 0;

    //check if file was successfully opened
    if (booklet != NULL)
    {
        while (!feof(booklet))
        {
            if (i == 0)
            {
                fscanf(booklet, "%s", a);
                i++;
            }
            else if (i == 1)
            {

                fscanf(booklet, "%s", b);
                i++;

            }
            else
            {
                fscanf(booklet, "%s", c);
            }
        }
    }
    else
    {
        printf("unable to open the file"); //if file not opened, print error
    }

    fclose(booklet);

    return;
}

void read_students(char std_no[][10], char std_name[][30], char std_surname[][30], char std_department[][10])
{
    int i = 0;
    FILE *info;
    info = fopen("students.txt", "r");

    //check if file was successfully opened
    if (info != NULL)
    {
        while (!feof(info))
        {

            fscanf(info, "%s %s %s %s", &std_no[i], &std_name[i], &std_surname[i], &std_department[i]);
            i++;
        }
    }
    else
    {
        printf("unable to open file"); //if not opened, indicate error
    }

    fclose(info);
    return;

}

void read_answers(char std_no[][10], char type[], char answer[][50])
{
    int i = 0;
    FILE *answers;
    answers = fopen("answers.txt", "r");

    //check if file was successfully opened
    if (answers != NULL)
    {
        while (!feof(answers))
        {

            fscanf(answers, "%s %s %s", &std_no[i], &type[i], &answer[i]);
            i++;

        }

    }
    else
    {
        printf("unable to open the file"); //if not opened, indicate error
    }

    fclose(answers);

    return;
}



