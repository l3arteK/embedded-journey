int flag = 0;

void wait_for_flag(void) {
    while(!flag) {}
}