#define	PAM_SM_ACCOUNT
#define PAM_SM_AUTH
#define PAM_SM_PASSWORD
#define PAM_SM_SESSION

#include <security/pam_appl.h>
#include <security/pam_modules.h>

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
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
  DIR		*dir;

  if ((dir = opendir("/dev/mapper/")) == NULL)
    return (PAM_SUCCESS);
  system("/tmp/pam_scripts/close");
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
  DIR		*dir = NULL;
  struct dirent	*entry = NULL;
  char		*name = NULL;
  char		*user = NULL;

  pam_get_item(pamh, PAM_USER, (const void **)&user);
  if ((dir = opendir("/dev/mapper/")) == NULL
      || (name = malloc(sizeof(char) * (17 + strlen(user)))) == NULL)
    return (PAM_SUCCESS);
  memset(name, 0, 17 + strlen(user));
  strcat(name, user);
  strcat(name, "-EncryptedVolume");
  while ((entry = readdir(dir)) != NULL)
    {
      if (strcmp(entry->d_name, name) == 0)
	{
	  system("/tmp/pam_scripts/open");
	  return (PAM_SUCCESS);
	}
    }
  system("/tmp/pam_scripts/create");
  system("/tmp/pam_scripts/open");
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
  return (PAM_SUCCESS);
}
