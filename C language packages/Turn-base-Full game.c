#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct playerdata
{
	char name[20];
};

int enemyattack(int enemybaseatk, float enemymultipledmg)
{
    return (rand() % (enemybaseatk + 1)) * enemymultipledmg;
}

float multiply(const float multipledmg, const int basedamage) // base dmg * multi
{
    return (float)(basedamage * multipledmg);
}

float poision(const float poisionDMG, const int basedamage)
{
    return (float)(basedamage * poisionDMG);
}

float shock(const float shockDMG, const float multipledmg, int basedamage)
{
    return (float)(basedamage * multipledmg) * shockDMG;
}

float healingwounds(float *playerhp, float maxhp) 
{
    return *playerhp * 1.56;
}
float deepwounds(float maxhp)
{
    return maxhp * 0.25;
}

void battle1(float *playerhp, float *enemyhp, int enemyatk, int *energy, int maxenergy, int *basedamage, float *multiplyDMG, float maxhp, char playername[]);
void battle2(float *playerhp, float *enemyhp, int enemyatk, int *energy, int maxenergy, int *basedamage, float *multiplyDMG, float maxhp, char playername[]);
void battle3(float *playerhp, float *enemyhp, int enemyatk, int *energy, int maxenergy, int *basedamage, float *multiplyDMG, float maxhp, char playername[]);

int main()
{
	FILE *fp = fopen("Hero info.txt", "w");
	if (fp == NULL)
	{
		printf("Error, NO FILE EXIST!");
		exit(1);
	}
	struct playerdata p;
	int battleFIRST = 1;
	int battleSECOND = 2;
	int battleTHIRD = 3;
    printf("Inster Hero Name : ");
    scanf("%s", p.name);
    fprintf(fp, "Hero Name : %s\n",p.name);
    fclose(fp);
    
    srand(time(0));
    //first encounter
    float playerhp = 92;
    float enemyhp = 165;
    int energy = 3, maxenergy = 5;
    int basedamage = 8;
    float multiply = 1.09;
    int maxhp = playerhp;
    
    int minb1 = 6, maxb1 = 12;
    int randEATK1 = minb1 + (rand() % (maxb1 - minb1 + 1));
    
    battle1(&playerhp, &enemyhp, randEATK1, &energy, maxenergy, &basedamage, &multiply, maxhp, p.name);
    
    if (playerhp > 0)    
    {
    	printf("---------------------------------------------------------\n");
	 	printf("%s Level up!\n+ 20 HP / + 2 ATK / + 0.09 Multiplier\nUnlock New Skill : Healing Wounds\n", p.name);
	 	printf("---------------------------------------------------------\n");
	 	FILE *fp = fopen("Hero info.txt", "a");
		if (fp == NULL)
		{
			printf("Error, NO FILE EXIST!");
			exit(1);
		}
		fprintf(fp, "Battle %d : WIN\n", battleFIRST);
		fclose(fp);
    }
    	
    playerhp = 112;
    maxhp = playerhp;
    enemyhp = 800;
    int minb2 = 10, maxb2 = 16;
    int randEATK2 = minb2 + (rand() % (maxb2 - minb2 + 1));
    energy = 3;
    battle2(&playerhp, &enemyhp, randEATK2, &energy, maxenergy, &basedamage, &multiply, maxhp, p.name);
    
    if (playerhp > 0)    
    {
    	printf("---------------------------------------------------------\n");
	 	printf("%s Level up!\n+ 23 HP / + 4 ATK / + 0.15 Multiplier\nUnlock New Skill : Deep SLASH!\n", p.name);
	 	printf("---------------------------------------------------------\n");
	 	FILE *fp = fopen("Hero info.txt", "a");
		if (fp == NULL)
		{
			printf("Error, NO FILE EXIST!");
			exit(1);
		}
		fprintf(fp, "Battle %d : WIN\n", battleSECOND);
		fclose(fp);
    }
    
    playerhp = 145;
    maxhp = playerhp;
    enemyhp = 1500;
    int minb3 = 18, maxb3 = 24;
    int randEATK3 = minb3 + (rand() % (maxb3 - minb3 + 1));
    energy = 3;
    battle3(&playerhp, &enemyhp, randEATK3, &energy, maxenergy, &basedamage, &multiply, maxhp, p.name);
    
    if (playerhp > 0)
    {
    FILE *fp = fopen("Hero info.txt", "a");
		if (fp == NULL)
		{
			printf("Error, NO FILE EXIST!");
			exit(1);
		}
		fprintf(fp, "Battle %d : WIN\n", battleTHIRD);
		printf("Result\nHero Name %s\Battle %d : WIN\nBattle %d : WIN\nBattle %d : WIN\n", p.name,battleFIRST,battleSECOND,battleTHIRD);
		fclose(fp);
	}
}

void battle1(float *playerhp, float *enemyhp, int enemyatk, int *energy, int maxenergy, int *basedamage, float *multiplyDMG, float maxhp, char playername[])
{
    int action;
    float totalplayer, totalenemy;
    float poisionDMG, shockDMG, enemymultipledmg;
    int basedmg;
    int baseDamagemin = 6, baseDamagemax = 12; // INCASE FOR SHOWING FIRST INFO
    srand(time(0));
    printf("%s HP : %.1f\nBase ATK : %d - %d\n",playername, *playerhp, baseDamagemin, baseDamagemax);
    printf("1.SLASH (Normal Attack) : Dealt 6 - 12 Damage\n");
    printf("2.Venomous Fang (Poison Skill Attack) : Dealt 5 - 11 Damage and additional Damage 45%% of damage\n");
    printf("3.Time Bomb (Detonate Skill Attack) : Dealt 2x Multiplier of damage\n");
    printf("---------------------------------------------------------\n");
    printf("Enemy : Goblin\nHP : 170\nATK : 6 - 12\n");
    printf("---------------------------------------------------------\n");
    
    while (*enemyhp > 0 && *playerhp > 0)
    {    
        float min1 = 0.45, max1 = 0.55;
        float randPOISION = min1 + ((float) rand() / RAND_MAX) * (max1 - min1);

        float min2 = 1.14, max2 = 1.20;
        float randMULTIPLY = min2 + ((float) rand() / RAND_MAX) * (max2 - min2);

        int baseDamagemin = 6, baseDamagemax = 12;
        int basedmg = baseDamagemin + ((float) rand() / RAND_MAX) * (baseDamagemax - baseDamagemin);
        
        poisionDMG = randPOISION;
        *multiplyDMG = randMULTIPLY;
        
        float min5 = 1.55, max5 = 1.89;
        enemymultipledmg = min5 + ((float)rand() / RAND_MAX) * (max5 - min5);
        
        printf("%s Energy : %d/%d\n",playername, *energy, maxenergy);
        printf("Select Action : ");
        scanf("%d", &action);
        if (action == 1) // Normal Attack
        {
            if (*energy < maxenergy)
            {
                *energy += 1;
                if (*energy > maxenergy)
                {
                    *energy = maxenergy;
                }
            }
            else
            {
                printf("Your Energy is already full!\n");
                printf("---------------------------------------------------------\n");
            }
            totalplayer = multiply(*multiplyDMG, basedmg);
            *enemyhp -= totalplayer;
            if(*enemyhp < 0) *enemyhp = 0;
            printf("---------------------------------------------------------\n");
            printf("SLASH ! : You did %.2f Damage\nEnemy HP: %.2f\n", totalplayer, *enemyhp);
        }
        else if (action == 2) // POISON Deal additional damage 45% of damage
        {
            if (*energy >= 2)
            {
                *energy -= 2;
                totalplayer = multiply(*multiplyDMG, basedmg);
                totalplayer += poision(poisionDMG, basedmg);
                *enemyhp -= totalplayer;
                if(*enemyhp < 0) *enemyhp = 0;
                printf("---------------------------------------------------------\n");
                printf("Venomous Fang! : You did %.2f Damage\nEnemy HP: %.2f\n", totalplayer, *enemyhp);
            }
            else
            {
                printf("Not enough Energy!\n");
                printf("---------------------------------------------------------\n");
                continue;
            }
        }
        else if (action == 3) // Detonate DAMAGE *2 MULTIPLY
        {
            if (*energy >= 2)
            {
                *energy -= 2;
                totalplayer = multiply(*multiplyDMG, basedmg) * 1.78;
                *enemyhp -= totalplayer;
                if(*enemyhp < 0) *enemyhp = 0;
                printf("---------------------------------------------------------\n");
                printf("Time Bomb : You did %.2f Damage\nEnemy HP: %.2f\n", totalplayer, *enemyhp);
            }
            else
            {
                printf("Not enough Energy!\n");
                printf("---------------------------------------------------------\n");
                continue;
            }
        }    
        if (*enemyhp <= 0) break;
        
        totalenemy = enemyattack(enemyatk, enemymultipledmg);
        *playerhp -= totalenemy;
        
        if(*playerhp < 0) *playerhp = 0;
        printf("---------------------------------------------------------\n");
        printf("You get hit %.2f Damage\nYour HP: %.2f\n", totalenemy, *playerhp);
        printf("---------------------------------------------------------\n");
    }
    if (*enemyhp <= 0) printf("%s win!\n", playername);
    else if (*playerhp <= 0)    
	{
	printf("%s lose!\n",playername);
	exit(0);
	}
}

void battle2(float *playerhp, float *enemyhp, int enemyatk, int *energy, int maxenergy, int *basedamage, float *multiplyDMG, float maxhp, char playername[])
{
    int action;
    float totalplayer, totalenemy;
    float poisionDMG, shockDMG, enemymultipledmg;
    int basedmg;
    
    int baseDamagemin = 8, baseDamagemax = 13;
    printf("---------------------------------------------------------\n");
    printf("%s HP : %.1f\nBase ATK : %d - %d\n",playername, *playerhp, baseDamagemin, baseDamagemax);
    printf("1.SLASH (Normal Attack) : Dealt 15 - 30 Damage\n");
    printf("2.Venomous Fang (Poison Skill Attack) : Dealt 15 - 25 Damage and additional Damage 45%% of damage\n");
    printf("3.Time Bomb (Detonate Skill Attack) : Dealt 2x Multiplier of damage\n");
    printf("4.Healing Wounds (Heal) : Heals 45%% of Max HP\n");
    printf("---------------------------------------------------------\n");
    
    printf("Enemy : Elder Goblin\nHP : 800\nATK : 10 - 16\n");
    printf("---------------------------------------------------------\n");
    
    while (*enemyhp > 0 && *playerhp > 0)
    {    
        float min1 = 0.45, max1 = 0.55;
        float randPOISION = min1 + ((float) rand() / RAND_MAX) * (max1 - min1);

        float min2 = 1.23, max2 = 1.29;
        float randMULTIPLY = min2 + ((float) rand() / RAND_MAX) * (max2 - min2);

        int baseDamagemin = 8, baseDamagemax = 13;
        int basedmg = baseDamagemin + ((float) rand() / RAND_MAX) * (baseDamagemax - baseDamagemin);
        
        poisionDMG = randPOISION;
        *multiplyDMG = randMULTIPLY;
        
        float min5 = 1.36, max5 = 1.45;
        enemymultipledmg = min5 + ((float)rand() / RAND_MAX) * (max5 - min5);
        
        printf("%s Energy : %d/%d\n",playername, *energy, maxenergy);
        printf("Select Action : ");
        scanf("%d", &action);
        if (action == 1) // Normal Attack
        {
            if (*energy < maxenergy)
            {
                *energy += 1;
                if (*energy > maxenergy)
                {
                    *energy = maxenergy;
                }
            }
            else
            {
                printf("Your Energy is already full!\n");
                printf("---------------------------------------------------------\n");
            }
            totalplayer = multiply(*multiplyDMG, basedmg);
            *enemyhp -= totalplayer;
            if(*enemyhp < 0) *enemyhp = 0;
            printf("---------------------------------------------------------\n");
            printf("SLASH ! : You did %.2f Damage\nEnemy HP: %.2f\n", totalplayer, *enemyhp);
        }
        else if (action == 2) // POISON
        {
            if (*energy >= 2)
            {
                *energy -= 2;
                totalplayer = multiply(*multiplyDMG, basedmg);
                totalplayer += poision(poisionDMG, basedmg);
                *enemyhp -= totalplayer;
                if(*enemyhp < 0) *enemyhp = 0;
                printf("---------------------------------------------------------\n");
                printf("Venomous Fang! : You did %.2f Damage\nEnemy HP: %.2f\n", totalplayer, *enemyhp);
            }
            else
            {
                printf("Not enough Energy!\n");
                printf("---------------------------------------------------------\n");
                continue;
            }
        }
        else if (action == 3) // Detonate
        {
            if (*energy >= 2)
            {
                *energy -= 2;
                totalplayer = multiply(*multiplyDMG, basedmg) * 1.78;
                *enemyhp -= totalplayer;
                if(*enemyhp < 0) *enemyhp = 0;
                printf("---------------------------------------------------------\n");
                printf("Time Bomb : You did %.2f Damage\nEnemy HP: %.2f\n", totalplayer, *enemyhp);
            }
            else
            {
                printf("Not enough Energy!\n");
                printf("---------------------------------------------------------\n");
                continue;
            }
        }
        else if (action == 4) // Healing Wounds 45 %
        {
            if (*energy >= 3)
            {
                *energy -= 3;
                float healingAmount = healingwounds(playerhp, maxhp);
                *playerhp += healingAmount;
                if(*playerhp > maxhp) *playerhp = maxhp;
                printf("---------------------------------------------------------\n");
                printf("Healing Wounds: You healed %.2f HP\nYour HP: %.2f\n", healingAmount, *playerhp);
            }
            else
            {
                printf("Not enough Energy!\n");
                printf("---------------------------------------------------------\n");
                continue;
            }
        }
        
        if (*enemyhp <= 0) break;
        
        totalenemy = enemyattack(enemyatk, enemymultipledmg);
        *playerhp -= totalenemy;
        
        if(*playerhp < 0) *playerhp = 0;
        printf("---------------------------------------------------------\n");
        printf("You get hit %.2f Damage\nYour HP: %.2f\n", totalenemy, *playerhp);
        printf("---------------------------------------------------------\n");
    }
    if (*enemyhp <= 0) printf("%s win!\n", playername);
    else if (*playerhp <= 0)    
	{
	printf("%s lose!\n",playername);
	exit(0);
	}
}

void battle3(float *playerhp, float *enemyhp, int enemyatk, int *energy, int maxenergy, int *basedamage, float *multiplyDMG, float maxhp, char playername[])
{
    int action;
    float totalplayer, totalenemy;
    float poisionDMG, shockDMG, enemymultipledmg, deepslash;
    int basedmg;
    
    int baseDamagemin = 13, baseDamagemax = 19;
    printf("---------------------------------------------------------\n");
    printf("%s HP : %.1f\nBase ATK : %d - %d\n",playername, *playerhp, baseDamagemin, baseDamagemax);
    printf("1.SLASH (Normal Attack) : Dealt 15 - 30 Damage\n");
    printf("2.Venomous Fang (Poison Skill Attack) : Dealt 15 - 25 Damage and additional Damage 45%% of damage\n");
    printf("3.Time Bomb (Detonate Skill Attack) : Dealt 2x Multiplier of damage\n");
    printf("4.Healing Wounds (Heal) : Heals 45%% of Max HP\n");
    printf("5.Deep SLASH! (Deep wounds Skill Attkack) : Deep slash dealt damage with 5% max hp of enemy");
    printf("---------------------------------------------------------\n");
    
    printf("Enemy : King Goblin\nHP : 1500\nATK : 18 - 24\n");
    printf("---------------------------------------------------------\n");
    
    while (*enemyhp > 0 && *playerhp > 0)
    {    
        float min1 = 0.45, max1 = 0.55;
        float randPOISION = min1 + ((float) rand() / RAND_MAX) * (max1 - min1);

        float min2 = 1.38, max2 = 1.47;
        float randMULTIPLY = min2 + ((float) rand() / RAND_MAX) * (max2 - min2);

        int baseDamagemin = 13, baseDamagemax = 19;
        int basedmg = baseDamagemin + ((float) rand() / RAND_MAX) * (baseDamagemax - baseDamagemin);
        
        poisionDMG = randPOISION;
        *multiplyDMG = randMULTIPLY;
        
        float min5 = 1.34, max5 = 1.56;
        enemymultipledmg = min5 + ((float)rand() / RAND_MAX) * (max5 - min5);
        
        printf("%s Energy : %d/%d\n",playername, *energy, maxenergy);
        printf("Select Action : ");
        scanf("%d", &action);
        if (action == 1) // Normal Attack
        {
            if (*energy < maxenergy)
            {
                *energy += 1;
                if (*energy > maxenergy)
                {
                    *energy = maxenergy;
                }
            }
            else
            {
                printf("Your Energy is already full!\n");
                printf("---------------------------------------------------------\n");
            }
            totalplayer = multiply(*multiplyDMG, basedmg);
            *enemyhp -= totalplayer;
            if(*enemyhp < 0) *enemyhp = 0;
            printf("---------------------------------------------------------\n");
            printf("SLASH ! : You did %.2f Damage\nEnemy HP: %.2f\n", totalplayer, *enemyhp);
        }
        else if (action == 2) // POISON
        {
            if (*energy >= 2)
            {
                *energy -= 2;
                totalplayer = multiply(*multiplyDMG, basedmg);
                totalplayer += poision(poisionDMG, basedmg);
                *enemyhp -= totalplayer;
                if(*enemyhp < 0) *enemyhp = 0;
                printf("---------------------------------------------------------\n");
                printf("Venomous Fang! : You did %.2f Damage\nEnemy HP: %.2f\n", totalplayer, *enemyhp);
            }
            else
            {
                printf("Not enough Energy!\n");
                printf("---------------------------------------------------------\n");
                continue;
            }
        }
        else if (action == 3) // Detonate
        {
            if (*energy >= 2)
            {
                *energy -= 2;
                totalplayer = multiply(*multiplyDMG, basedmg) * 1.78;
                *enemyhp -= totalplayer;
                if(*enemyhp < 0) *enemyhp = 0;
                printf("---------------------------------------------------------\n");
                printf("Time Bomb : You did %.2f Damage\nEnemy HP: %.2f\n", totalplayer, *enemyhp);
            }
            else
            {
                printf("Not enough Energy!\n");
                printf("---------------------------------------------------------\n");
                continue;
            }
        }
        else if (action == 4) // Healing Wounds 45 %
        {
            if (*energy >= 3)
            {
                *energy -= 3;
                float healingAmount = healingwounds(playerhp, maxhp);
                *playerhp += healingAmount;
                if(*playerhp > maxhp) *playerhp = maxhp;
                printf("---------------------------------------------------------\n");
                printf("Healing Wounds: You healed %.2f HP\nYour HP: %.2f\n", healingAmount, *playerhp);
            }
            else
            {
                printf("Not enough Energy!\n");
                printf("---------------------------------------------------------\n");
                continue;
            }
        }
        else if (action == 5) // Deep SLASH! deal damage with max hp %
        {
            if (*energy >= 5)
            {
                *energy -= 5;
                totalplayer = multiply(*multiplyDMG, basedmg);
                deepslash = *enemyhp * 0.25;
                *enemyhp -= (totalplayer + deepslash);
                if(*enemyhp < 0) *enemyhp = 0;
                printf("---------------------------------------------------------\n");
                printf("Deep Slash!: You did %.2f Damage (%.2f from Deep Wounds)\n", totalplayer + deepslash, deepslash);
        		printf("Enemy HP: %.2f\n", *enemyhp);
            }
            else
            {
                printf("Not enough Energy!\n");
                printf("---------------------------------------------------------\n");
                continue;
            }
        }
        
        if (*enemyhp <= 0) break;
        
        totalenemy = enemyattack(enemyatk, enemymultipledmg);
        *playerhp -= totalenemy;
        
        if(*playerhp < 0) *playerhp = 0;
        printf("---------------------------------------------------------\n");
        printf("You get hit %.2f Damage\nYour HP: %.2f\n", totalenemy, *playerhp);
        printf("---------------------------------------------------------\n");
    }
    if (*enemyhp <= 0) printf("%s win!\n", playername);
    else if (*playerhp <= 0)    
	{
	printf("%s lose!\n",playername);
	exit(0);
	}
}
