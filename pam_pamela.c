#define	PAM_SM_ACCOUNT
#define PAM_SM_AUTH
#define PAM_SM_PASSWORD
#define PAM_SM_SESSION

#include <security/pam_appl.h>
#include <security/pam_modules.h>

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/* PAM Session Creation */
extern int	pam_sm_open_session(pam_handle_t *pamh, int flags,
				    int argc, const char **argv)
{
  printf("Session Creation\n");
  printf("flags:%d\n", flags);
  printf("argc:%d\n", argc);
  for (unsigned int i = 0; i < argc; ++i)
    printf("argv[%d]:%s\n", argv[i]);
  sleep(1);
  return (PAM_SUCCESS);
}

/* PAM Session Cleanup */
extern int	pam_sm_close_session(pam_handle_t *pamh, int flags,
				     int argc, const char **argv)
{
  printf("Session Cleanup\n");
  printf("flags:%d\n", flags);
  printf("argc:%d\n", argc);
  for (unsigned int i = 0; i < argc; ++i)
    printf("argv[%d]:%s\n", argv[i]);
  sleep(1);
  return (PAM_SUCCESS);
}

/* PAM Accounting */
extern int	pam_sm_acct_mgmt(pam_handle_t *pamh, int flags,
				 int argc, const char **argv)
{
  printf("Accounting\n");
  printf("flags:%d\n", flags);
  printf("argc:%d\n", argc);
  for (unsigned int i = 0; i < argc; ++i)
    printf("argv[%d]:%s\n", argv[i]);
  sleep(1);
  return (PAM_SUCCESS);
}

/* PAM Authentication Verification */
extern int	pam_sm_authenticate(pam_handle_t *pamh, int flags,
				    int argc, const char **argv)
{
  printf("Authentication Verification\n");
  printf("flags:%d\n", flags);
  printf("argc:%d\n", argc);
  for (unsigned int i = 0; i < argc; ++i)
    printf("argv[%d]:%s\n", argv[i]);
  sleep(1);
  return (PAM_SUCCESS);
}

/* PAM Setting Credentials */
extern int	pam_sm_setcred(pam_handle_t *pamh, int flags,
			       int argc, const char **argv)
{
  printf("Setting Credentials\n");
  printf("flags:%d\n", flags);
  printf("argc:%d\n", argc);
  for (unsigned int i = 0; i < argc; ++i)
    printf("argv[%d]:%s\n", argv[i]);
  sleep(1);
  return (PAM_SUCCESS);
}

/* PAM Password Changes */
extern int	pam_sm_chauthtok(pam_handle_t *pamh, int flags,
				 int argc, const char **argv)
{
  printf("Password Changes\n");
  printf("flags:%d\n", flags);
  printf("argc:%d\n", argc);
  for (unsigned int i = 0; i < argc; ++i)
    printf("argv[%d]:%s\n", argv[i]);
  sleep(1);
  return (PAM_SUCCESS);
}
