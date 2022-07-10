/*************************************************************************
    > File Name: epoll_server.h
    > Author: Rytonli
    > Mail: rytonli@163.com
    > Created Time: Sun 10 Jul 2022 03:08:56 PM CST
 ************************************************************************/

#ifndef EPOLL_SERVER_H
#define EPOLL_SERVER_H

int init_listen_fd(int port, int epfd);
void epoll_run(int port);
void do_accept(int lfd, int epfd);
void do_read(int cfd, int epfd);
int get_line(int sock, char *buf, int size);
void disconnect(int cfd, int epfd);
void http_request(const char* request, int cfd);
void send_respond_head(int cfd, int no, const char* desp, const char* type, long len);
void send_file(int cfd, const char* filename);
void send_dir(int cfd, const char* dirname);
void encode_str(char* to, int tosize, const char* from);
void decode_str(char *to, char *from);
const char *get_file_type(const char *name);
void send_error(int cfd, int status, char *title, char *text);

#endif
