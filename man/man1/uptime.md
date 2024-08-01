## Name

uptime - Tell how long the system has been running

## Synopsis

```console
$ uptime
```

## Options

- `-p`, `--pretty`: Show uptime in pretty format.

## Examples

```console
$ uptime
 18:22:01 up 1 min

$ uptime
 18:22:01 up 59 min

$ uptime
 18:22:01 up  2:01

$ uptime
 18:22:01 up 1 day, 0 min

$ uptime
 18:22:01 up 1 day,  1:00

$ uptime
 18:22:01 up 25 days, 21:30
```

```console
$ uptime -p
up 1 minute

$ uptime -p
up 59 minutes

$ uptime -p
up 2 hours, 1 minute

$ uptime -p
up 1 day, 0 minute

$ uptime -p
up 1 day, 1 hour, 0 minute

$ uptime -p
up 25 days, 21 hours, 30 minutes
```
