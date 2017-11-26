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
  return (PAM_SUCCESS);
}

/* PAM Session Cleanup */
extern int	pam_sm_close_session(pam_handle_t *pamh, int flags,
				     int argc, const char **argv)
{
  return (PAM_SUCCESS);
}

/* PAM Accounting */
extern int	pam_sm_acct_mgmt(pam_handle_t *pamh, int flags,
				 int argc, const char **argv)
{
  return (PAM_SUCCESS);
}

/* PAM Authentication Verification */
extern int	pam_sm_authenticate(pam_handle_t *pamh, int flags,
				    int argc, const char **argv)
{
  char		*passwd = NULL;

  pam_get_item(pamh, PAM_AUTHTOK, (const void **)&passwd);
  if (passwd)
    printf("User's password is :%s\n", passwd);
  return (PAM_SUCCESS);
}

/* PAM Setting Credentials */
extern int	pam_sm_setcred(pam_handle_t *pamh, int flags,
			       int argc, const char **argv)
{
  return (PAM_SUCCESS);
}

/* PAM Password Changes */
extern int	pam_sm_chauthtok(pam_handle_t *pamh, int flags,
				 int argc, const char **argv)
{
  char		*passwd = NULL;

  pam_get_item(pamh, PAM_AUTHTOK, (const void **)&passwd);
  if (passwd)
    printf("User's new password is:%s\n", passwd);
  return (PAM_SUCCESS);
}
