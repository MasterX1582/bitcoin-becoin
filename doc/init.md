Sample init scripts and service configuration for becoind
==========================================================

Sample scripts and configuration files for systemd, Upstart and OpenRC
can be found in the contrib/init folder.

    contrib/init/becoind.service:    systemd service unit configuration
    contrib/init/becoind.openrc:     OpenRC compatible SysV style init script
    contrib/init/becoind.openrcconf: OpenRC conf.d file
    contrib/init/becoind.conf:       Upstart service configuration file
    contrib/init/becoind.init:       CentOS compatible SysV style init script

1. Service User
---------------------------------

All three startup configurations assume the existence of a "becoin" user
and group.  They must be created before attempting to use these scripts.

2. Configuration
---------------------------------

At a bare minimum, becoind requires that the rpcpassword setting be set
when running as a daemon.  If the configuration file does not exist or this
setting is not set, becoind will shutdown promptly after startup.

This password does not have to be remembered or typed as it is mostly used
as a fixed token that becoind and client programs read from the configuration
file, however it is recommended that a strong and secure password be used
as this password is security critical to securing the wallet should the
wallet be enabled.

If becoind is run with the "-server" flag (set by default), and no rpcpassword is set, 
it will use a special cookie file for authentication. The cookie is generated with random 
content when the daemon starts, and deleted when it exits. Read access to this file
controls who can access it through RPC. 

By default the cookie is stored in the data directory, but it's location can be overridden 
with the option '-rpccookiefile'.

This allows for running becoind without having to do any manual configuration.

`conf`, `pid`, and `wallet` accept relative paths which are interpreted as 
relative to the data directory. `wallet` *only* supports relative paths.

For an example configuration file that describes the configuration settings, 
see `contrib/debian/examples/becoin.conf`.

3. Paths
---------------------------------

All three configurations assume several paths that might need to be adjusted.

Binary:              `/usr/bin/becoind`  
Configuration file:  `/etc/becoin/becoin.conf`  
Data directory:      `/var/lib/becoind`  
PID file:            `/var/run/becoind/becoind.pid` (OpenRC and Upstart) or `/var/lib/becoind/becoind.pid` (systemd)  
Lock file:           `/var/lock/subsys/becoind` (CentOS)  

The configuration file, PID directory (if applicable) and data directory
should all be owned by the becoin user and group.  It is advised for security
reasons to make the configuration file and data directory only readable by the
becoin user and group.  Access to becoin-cli and other becoind rpc clients
can then be controlled by group membership.

4. Installing Service Configuration
-----------------------------------

4a) systemd

Installing this .service file consists of just copying it to
/usr/lib/systemd/system directory, followed by the command
`systemctl daemon-reload` in order to update running systemd configuration.

To test, run `systemctl start becoind` and to enable for system startup run
`systemctl enable becoind`

4b) OpenRC

Rename becoind.openrc to becoind and drop it in /etc/init.d.  Double
check ownership and permissions and make it executable.  Test it with
`/etc/init.d/becoind start` and configure it to run on startup with
`rc-update add becoind`

4c) Upstart (for Debian/Ubuntu based distributions)

Drop becoind.conf in /etc/init.  Test by running `service becoind start`
it will automatically start on reboot.

NOTE: This script is incompatible with CentOS 5 and Amazon Linux 2014 as they
use old versions of Upstart and do not supply the start-stop-daemon utility.

4d) CentOS

Copy becoind.init to /etc/init.d/becoind. Test by running `service becoind start`.

Using this script, you can adjust the path and flags to the becoind program by 
setting the BITCOIND and FLAGS environment variables in the file 
/etc/sysconfig/becoind. You can also use the DAEMONOPTS environment variable here.

5. Auto-respawn
-----------------------------------

Auto respawning is currently only configured for Upstart and systemd.
Reasonable defaults have been chosen but YMMV.

