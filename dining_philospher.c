//dinning philosher
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define Philo 5
sem_t forks[Philo];
void *dine(void *arg) {
    int id = *(int *)arg;
    while (1) {
        printf("Philo %d is thinking.\n", id);
        sleep(1);
        sem_wait(&forks[id]); sem_wait(&forks[(id + 1) % Philo]);
        printf("Philo %d is eating.\n", id);
        sleep(1);
        sem_post(&forks[id]); sem_post(&forks[(id + 1) % Philo]);
    }
}
int main() {
    pthread_t Philo[Philo]; int ids[Philo];
    for (int i = 0; i < Philo; i++) sem_init(&forks[i], 0, 1);
    for (int i = 0; i < Philo; i++) {
        ids[i] = i; pthread_create(&Philo[i], NULL, dine, &ids[i]);
    }
    for (int i = 0; i < Philo; i++) pthread_join(Philo[i], NULL);
    for (int i = 0; i < Philo; i++) sem_destroy(&forks[i]);

}
