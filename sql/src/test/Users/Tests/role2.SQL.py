import os, sys
import copy
try:
    import subprocess
except ImportError:
    # use private copy for old Python versions
    import MonetDBtesting.subprocess26 as subprocess

def client(cmd, env = os.environ):
    clt = subprocess.Popen(cmd, env=env, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    sys.stdout.write(clt.stdout.read())
    clt.stdout.close()
    sys.stderr.write(clt.stderr.read())
    clt.stderr.close()


def main():
    testenv = copy.deepcopy(os.environ)
    testenv['DOTMONETDBFILE'] = '.testuser'
    f = open(testenv['DOTMONETDBFILE'], 'w')
    f.write('user=my_user2\npassword=p2\n')
    f.close()
    clcmd = str(os.getenv('SQL_CLIENT')) + "< %s" % ('%s/../role.sql' % os.getenv('RELSRCDIR'))
    client(clcmd, testenv)
    os.unlink(testenv['DOTMONETDBFILE'])

main()
